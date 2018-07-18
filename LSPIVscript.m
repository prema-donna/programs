% Based on
% 'Line-Scanning Particle Image Velocimetry: an Optical Approach for
% Quantifying a Wide Range of Blood Flow Speeds in Live Animals'
% by Tyson N. Kim, Patrick W. Goodwill, Yeni Chen, Steven M. Conolly, Chris
% B. Schaffer, Dorian Liepmann, Rong A. Wang
%
% PWG 3/28/2012

close all

% Parameters to improve fits
maxGaussWidth = 100;  % maximum width of peak during peak fitting

% Judge correctness of fit
numstd        = 3;  %num of stdard deviation from the mean before flagging
windowsize    = 1463; %in # scans, this will be converted to velocity points
                      %if one scan is 1/1463 s, then windowsize=1463 means
                      %a 1 second moving window.  Choose the window size
                      %according to experiment.
total_time = 2.05;
pixel_length = 0.06;
num_scans = 3000;                      
shiftamt = 10; %if artery, use 1, if capillary, use 5. If vein, use...10
skipamt = 5; %Skips 4 out of every 5 points. Saves a lot of simulation time.
numavgs = 0; %used to process noisy or slow data. Can leave this at 0. 

%% Import the data from a multi-frame tif and make into a single array
%  The goal is a file format that is one single array,
%  so modify this section to accomodate your raw data format. 
disp('Import raw data from model');
[fname,pathname]=uigetfile('*.TIF','Pick a linescan file');%loads file
if fname == 0; beep; disp('Cancelled');  end
imageLines = imimportTif([pathname fname])';


%% choose where in the image to process
imagesc(imageLines(1:size(imageLines,2),:))
colormap('gray')

title('Select the boundaries of the region of interest 1/2');
[X1,Y1] = ginput(1);
line([X1 X1],[1 size(imageLines,2)]);

title('Select the boundaries of the region of interest 2/2');
[X2,Y2] = ginput(1);
line([X2 X2],[1 size(imageLines,2)]);
refresh
pause(.01);

startColumn   = round(min(X1, X2));      % Defines what part of the image we perform LSPIV on.
endColumn     = round(max(X1, X2));

%% subtract the background signal (PWG 6/4/2009)
tic
disp('DC Correction')
DCoffset = sum(imageLines,1) / size(imageLines,1);
imageLinesDC = imageLines - repmat(DCoffset,size(imageLines,1),1);

%% do LSPIV correlation
disp('LSPIV Begin');

scene_fft  = fft(imageLinesDC(1:end-shiftamt,:),[],2);
test_img   = zeros(size(scene_fft));
test_img(:,startColumn:endColumn)   = imageLinesDC(shiftamt+1:end, startColumn:endColumn);
test_fft   = fft(test_img,[],2);
W      = 1./sqrt(abs(scene_fft)) ./ sqrt(abs(test_fft)); % phase only

LSPIVresultFFT      = scene_fft .* conj(test_fft) .* W; 
LSPIVresult         = ifft(LSPIVresultFFT,[],2);
disp('LSPIV Complete');
    
%% find shift amounts
disp('Find the Peak Velocity Values');
velocity = [];
maxpxlshift = round(size(imageLines,2)/2)-1;

index_vals = skipamt:skipamt:(size(LSPIVresult,1)-numavgs);
numpixels = size(LSPIVresult,2);
velocity  = nan(size(index_vals));
amps      = nan(size(index_vals));
sigmas    = nan(size(index_vals));
goodness  = nan(size(index_vals));

velocity_time = nan(size(index_vals));
series_time = nan(size(index_vals));

%% iterate through
close all
for index = 1:length(index_vals)
    
    if mod(index_vals(index),100) == 0
        fprintf('line: %d\n',index_vals(index))
    end
    
    LSPIVresultAVG   = fftshift(sum(LSPIVresult(index_vals(index):index_vals(index)+numavgs,:),1)) ...
                                      / max(sum(LSPIVresult(index_vals(index):index_vals(index)+numavgs,:),1));
    
    % find a good guess for the center
    c = zeros(1, numpixels);
    c(numpixels/2-maxpxlshift:numpixels/2+maxpxlshift) = ...
        LSPIVresultAVG(numpixels/2-maxpxlshift:numpixels/2+maxpxlshift);
    [maxval, maxindex] = max(c);
    
    % fit a guassian to the xcorrelation to get a subpixel shift
    options = fitoptions('gauss1');
    options.Lower      = [0    numpixels/2-maxpxlshift   0            0];
    options.Upper      = [1e9  numpixels/2+maxpxlshift  maxGaussWidth 1];
    options.StartPoint = [1 maxindex 10 .1];
        
    [q,good] = fit((1:length(LSPIVresultAVG))',LSPIVresultAVG','a1*exp(-((x-b1)/c1)^2) + d1',options);
    
    %save the data
    velocity(index)  = abs(q.b1 - size(LSPIVresult,2)/2 - 1)/shiftamt;
    amps(index)      = q.a1;
    sigmas(index)    = q.c1;
    goodness(index)  = good.rsquare;
    
    velocity_time(index) = (num_scans*pixel_length/total_time)*velocity(index);
    series_time(index) = (total_time/length(index_vals))*index;

    % plot the data out
    figure(1)
    subplot(1,2,1)
    hold off
    plot(LSPIVresultAVG);
    hold all
    plot(q);
    title('Average LSPIV fit');
    xlabel('Pixel length');
    ylabel('Correlation');
    xlim([1 numpixels]);
    ylim([0 1]);
    
    
    subplot(1,2,2)
    plot(series_time,velocity_time)
    title('Velocity(um/s) vs. Time(s)');
    ylabel('Velocity(um/s)');
    xlabel('Time(s)'); 
    xlim([0 total_time]);
    pause(.01);
end
%% find possible bad fits
toc

% Find bad velocity points using a moving window 
pixel_windowsize = round(windowsize / skipamt);

badpixels = zeros(size(velocity));
for index = 1:1:length(velocity)-pixel_windowsize
    pmean = mean(velocity(index:index+pixel_windowsize-1)); %partial window mean
    pstd  = std(velocity(index:index+pixel_windowsize-1));  %partial std 
    
    pbadpts = find((velocity(index:index+pixel_windowsize-1) > pmean + pstd*numstd) | ...
                   (velocity(index:index+pixel_windowsize-1) < pmean - pstd*numstd));

    badpixels(index+pbadpts-1) = badpixels(index+pbadpts-1) + 1; %running sum of bad pts
end
badvals  = find(badpixels > 0); % turn pixels into indicies
goodvals = find(badpixels == 0);

meanvel  = (num_scans*pixel_length/total_time)*mean(velocity(goodvals)); %overall mean
stdvel   = (num_scans*pixel_length/total_time)*std(velocity(goodvals));  %overall std


% show results
figure(2)
subplot(3,1,1)
imgtmp = zeros([size(imageLines(:,startColumn:endColumn),2) size(imageLines(:,startColumn:endColumn),1) 3]); % to enable BW and color simultaneously
imgtmp(:,:,1) = imageLines(:,startColumn:endColumn)'; imgtmp(:,:,2) = imageLines(:,startColumn:endColumn)'; imgtmp(:,:,3) = imageLines(:,startColumn:endColumn)';
imagesc(imgtmp/max(max(max(imgtmp))))
title('Model Data');
ylabel('(Pixels)');
xlim([0 num_scans-skipamt-numavgs]);
%colormap('gray');

subplot(3,1,2)
imagesc(index_vals,-numpixels/2:numpixels/2,fftshift(LSPIVresult(:,:),2)');
title('LSPIV xcorrected');
ylabel({'Displacement'; '(Pixels/Scan)'});
xlim([skipamt num_scans-skipamt-numavgs])


subplot(3,1,3)
plot(series_time, velocity_time,'.');
hold all
plot(total_time/length(index_vals)*index_vals(badvals)/skipamt, (num_scans*pixel_length/total_time)*velocity(badvals), 'ro');
hold off
xlim([0 total_time]);
ylim([meanvel-stdvel*4 meanvel+stdvel*4]);
title('Fitted Velocity vs Time');
ylabel({'Fitted Velocity'; '(um/s)'});
xlabel({'Time'; '(s)'});

h = line([0 total_time], [meanvel meanvel]);
set(h, 'LineStyle','--','Color','k');
h = line([0 total_time], [meanvel+stdvel meanvel+stdvel]);
set(h, 'LineStyle','--','Color',[.5 .5 .5]);
h = line([0 total_time], [meanvel-stdvel meanvel-stdvel]);
set(h, 'LineStyle','--','Color',[.5 .5 .5]);
fprintf('\nMean  Velocity %0.2f [um/s]\n', meanvel);
fprintf('Stdev Velocity %0.2f [um/s]\n', stdvel);




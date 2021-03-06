%clc 
%clear all

load ResultsEmb1_Part1.mat NPemb1 %important
disp_factor = NPemb1; %important
l_disp_factor = length(disp_factor);
count = 100;

%conventions: highest (180-200), higher (160-179), high (140-159), 
%highlow (120-139), medhigh (100-119), med (80-99), medlow (60-79),
%low (40-59), lower (20-39), lowest (0-19)
%for emb2, these are all divided by 2. So highest is 90-100 and so on.
num_normalize_highest = 0; 
num_normalize_higher = 0; 
num_normalize_high = 0; 
num_normalize_highlow = 0; 
num_normalize_medhigh = 0; 
num_normalize_med = 0; 
num_normalize_medlow = 0; 
num_normalize_low = 0; 
num_normalize_lower = 0; 
num_normalize_lowest = 0;
total_nn_highest = 0; 
total_nn_higher = 0; 
total_nn_high = 0; 
total_nn_highlow = 0; 
total_nn_medhigh = 0; 
total_nn_med = 0;
total_nn_medlow = 0;
total_nn_low = 0;
total_nn_lower = 0; 
total_nn_lowest = 0; 
normalize_highest = 0; 
normalize_higher = 0; 
normalize_high = 0; 
normalize_highlow = 0; 
normalize_medhigh = 0; 
normalize_med = 0; 
normalize_medlow = 0; 
normalize_low = 0; 
normalize_lower = 0;
normalize_lowest = 0;

for i = 1:l_disp_factor
    if disp_factor(i,4)>= 180 && disp_factor(i,4)< 200 %emb3
        num_normalize_highest = num_normalize_highest + 1;
        total_nn_highest = total_nn_highest + disp_factor(i,4)*disp_factor(i,5);
        normalize_highest = total_nn_highest/num_normalize_highest;
    end
    if disp_factor(i,4)>= 160 && disp_factor(i,4)< 180 %emb3
        num_normalize_higher = num_normalize_higher + 1;
        total_nn_higher = total_nn_higher + disp_factor(i,4)*disp_factor(i,5);
        normalize_higher = total_nn_higher/num_normalize_higher;
    end
    if disp_factor(i,4)>= 140 && disp_factor(i,4)< 160 %emb3
        num_normalize_high = num_normalize_high + 1;
        total_nn_high = total_nn_high + disp_factor(i,4)*disp_factor(i,5);
        normalize_high = total_nn_high/num_normalize_high;
    end
    if disp_factor(i,4)>= 120 && disp_factor(i,4)< 140 %emb3
        num_normalize_highlow = num_normalize_highlow + 1;
        total_nn_highlow = total_nn_highlow + disp_factor(i,4)*disp_factor(i,5);
        normalize_highlow = total_nn_highlow/num_normalize_highlow;
    end
    if disp_factor(i,4)>= 100 && disp_factor(i,4)< 120 %emb3
        num_normalize_medhigh = num_normalize_medhigh + 1;
        total_nn_medhigh = total_nn_medhigh + disp_factor(i,4)*disp_factor(i,5);
        normalize_medhigh = total_nn_medhigh/num_normalize_medhigh;
    end
    if disp_factor(i,4)>= 80 && disp_factor(i,4)< 100 %emb3
        num_normalize_med = num_normalize_med + 1;
        total_nn_med = total_nn_med + disp_factor(i,4)*disp_factor(i,5);
        normalize_med = total_nn_med/num_normalize_med;
    end
    if disp_factor(i,4)>= 60 && disp_factor(i,4)< 80 %emb3
        num_normalize_medlow = num_normalize_medlow + 1;
        total_nn_medlow = total_nn_medlow + disp_factor(i,4)*disp_factor(i,5);
        normalize_medlow = total_nn_medlow/num_normalize_medlow;
    end
    if disp_factor(i,4)>= 40 && disp_factor(i,4)< 60 %emb3
        num_normalize_low = num_normalize_low + 1;
        total_nn_low = total_nn_low + disp_factor(i,4)*disp_factor(i,5);
        normalize_low = total_nn_low/num_normalize_low;
    end
    if disp_factor(i,4)>= 20 && disp_factor(i,4)< 40 %emb3
        num_normalize_lower = num_normalize_lower + 1;
        total_nn_lower = total_nn_lower + disp_factor(i,4)*disp_factor(i,5);
        normalize_lower = total_nn_lower/num_normalize_lower;
    end
    if disp_factor(i,4)>= 0 && disp_factor(i,4)< 20 %emb3
        num_normalize_lowest = num_normalize_lowest + 1;
        total_nn_lowest = total_nn_lowest + disp_factor(i,4)*disp_factor(i,5);
        normalize_lowest = total_nn_lowest/num_normalize_lowest;
    end
end

load ResultsEmb1_Part2.mat NPemb1 %important
disp_factor = NPemb1; %important
l_disp_factor = length(disp_factor);

for i = 1:l_disp_factor
    if disp_factor(i,4)>= 180 && disp_factor(i,4)< 200 %emb3
        num_normalize_highest = num_normalize_highest + 1;
        total_nn_highest = total_nn_highest + disp_factor(i,4)*disp_factor(i,5);
        normalize_highest = total_nn_highest/num_normalize_highest;
    end
    if disp_factor(i,4)>= 160 && disp_factor(i,4)< 180 %emb3
        num_normalize_higher = num_normalize_higher + 1;
        total_nn_higher = total_nn_higher + disp_factor(i,4)*disp_factor(i,5);
        normalize_higher = total_nn_higher/num_normalize_higher;
    end
    if disp_factor(i,4)>= 140 && disp_factor(i,4)< 160 %emb3
        num_normalize_high = num_normalize_high + 1;
        total_nn_high = total_nn_high + disp_factor(i,4)*disp_factor(i,5);
        normalize_high = total_nn_high/num_normalize_high;
    end
    if disp_factor(i,4)>= 120 && disp_factor(i,4)< 140 %emb3
        num_normalize_highlow = num_normalize_highlow + 1;
        total_nn_highlow = total_nn_highlow + disp_factor(i,4)*disp_factor(i,5);
        normalize_highlow = total_nn_highlow/num_normalize_highlow;
    end
    if disp_factor(i,4)>= 100 && disp_factor(i,4)< 120 %emb3
        num_normalize_medhigh = num_normalize_medhigh + 1;
        total_nn_medhigh = total_nn_medhigh + disp_factor(i,4)*disp_factor(i,5);
        normalize_medhigh = total_nn_medhigh/num_normalize_medhigh;
    end
    if disp_factor(i,4)>= 80 && disp_factor(i,4)< 100 %emb3
        num_normalize_med = num_normalize_med + 1;
        total_nn_med = total_nn_med + disp_factor(i,4)*disp_factor(i,5);
        normalize_med = total_nn_med/num_normalize_med;
    end
    if disp_factor(i,4)>= 60 && disp_factor(i,4)< 80 %emb3
        num_normalize_medlow = num_normalize_medlow + 1;
        total_nn_medlow = total_nn_medlow + disp_factor(i,4)*disp_factor(i,5);
        normalize_medlow = total_nn_medlow/num_normalize_medlow;
    end
    if disp_factor(i,4)>= 40 && disp_factor(i,4)< 60 %emb3
        num_normalize_low = num_normalize_low + 1;
        total_nn_low = total_nn_low + disp_factor(i,4)*disp_factor(i,5);
        normalize_low = total_nn_low/num_normalize_low;
    end
    if disp_factor(i,4)>= 20 && disp_factor(i,4)< 40 %emb3
        num_normalize_lower = num_normalize_lower + 1;
        total_nn_lower = total_nn_lower + disp_factor(i,4)*disp_factor(i,5);
        normalize_lower = total_nn_lower/num_normalize_lower;
    end
    if disp_factor(i,4)>= 0 && disp_factor(i,4)< 20 %emb3
        num_normalize_lowest = num_normalize_lowest + 1;
        total_nn_lowest = total_nn_lowest + disp_factor(i,4)*disp_factor(i,5);
        normalize_lowest = total_nn_lowest/num_normalize_lowest;
    end
end

load ResultsEmb1_Part3.mat NPemb1 %important
disp_factor = NPemb1; %important
l_disp_factor = length(disp_factor);

for i = 1:l_disp_factor
    if disp_factor(i,4)>= 180 && disp_factor(i,4)< 200 %emb3
        num_normalize_highest = num_normalize_highest + 1;
        total_nn_highest = total_nn_highest + disp_factor(i,4)*disp_factor(i,5);
        normalize_highest = total_nn_highest/num_normalize_highest;
    end
    if disp_factor(i,4)>= 160 && disp_factor(i,4)< 180 %emb3
        num_normalize_higher = num_normalize_higher + 1;
        total_nn_higher = total_nn_higher + disp_factor(i,4)*disp_factor(i,5);
        normalize_higher = total_nn_higher/num_normalize_higher;
    end
    if disp_factor(i,4)>= 140 && disp_factor(i,4)< 160 %emb3
        num_normalize_high = num_normalize_high + 1;
        total_nn_high = total_nn_high + disp_factor(i,4)*disp_factor(i,5);
        normalize_high = total_nn_high/num_normalize_high;
    end
    if disp_factor(i,4)>= 120 && disp_factor(i,4)< 140 %emb3
        num_normalize_highlow = num_normalize_highlow + 1;
        total_nn_highlow = total_nn_highlow + disp_factor(i,4)*disp_factor(i,5);
        normalize_highlow = total_nn_highlow/num_normalize_highlow;
    end
    if disp_factor(i,4)>= 100 && disp_factor(i,4)< 120 %emb3
        num_normalize_medhigh = num_normalize_medhigh + 1;
        total_nn_medhigh = total_nn_medhigh + disp_factor(i,4)*disp_factor(i,5);
        normalize_medhigh = total_nn_medhigh/num_normalize_medhigh;
    end
    if disp_factor(i,4)>= 80 && disp_factor(i,4)< 100 %emb3
        num_normalize_med = num_normalize_med + 1;
        total_nn_med = total_nn_med + disp_factor(i,4)*disp_factor(i,5);
        normalize_med = total_nn_med/num_normalize_med;
    end
    if disp_factor(i,4)>= 60 && disp_factor(i,4)< 80 %emb3
        num_normalize_medlow = num_normalize_medlow + 1;
        total_nn_medlow = total_nn_medlow + disp_factor(i,4)*disp_factor(i,5);
        normalize_medlow = total_nn_medlow/num_normalize_medlow;
    end
    if disp_factor(i,4)>= 40 && disp_factor(i,4)< 60 %emb3
        num_normalize_low = num_normalize_low + 1;
        total_nn_low = total_nn_low + disp_factor(i,4)*disp_factor(i,5);
        normalize_low = total_nn_low/num_normalize_low;
    end
    if disp_factor(i,4)>= 20 && disp_factor(i,4)< 40 %emb3
        num_normalize_lower = num_normalize_lower + 1;
        total_nn_lower = total_nn_lower + disp_factor(i,4)*disp_factor(i,5);
        normalize_lower = total_nn_lower/num_normalize_lower;
    end
    if disp_factor(i,4)>= 0 && disp_factor(i,4)< 20 %emb3
        num_normalize_lowest = num_normalize_lowest + 1;
        total_nn_lowest = total_nn_lowest + disp_factor(i,4)*disp_factor(i,5);
        normalize_lowest = total_nn_lowest/num_normalize_lowest;
    end
end

load ResultsEmb1_Part4.mat NPemb1 %important
disp_factor = NPemb1; %important
l_disp_factor = length(disp_factor);

for i = 1:l_disp_factor
    if disp_factor(i,4)>= 180 && disp_factor(i,4)< 200 %emb3
        num_normalize_highest = num_normalize_highest + 1;
        total_nn_highest = total_nn_highest + disp_factor(i,4)*disp_factor(i,5);
        normalize_highest = total_nn_highest/num_normalize_highest;
    end
    if disp_factor(i,4)>= 160 && disp_factor(i,4)< 180 %emb3
        num_normalize_higher = num_normalize_higher + 1;
        total_nn_higher = total_nn_higher + disp_factor(i,4)*disp_factor(i,5);
        normalize_higher = total_nn_higher/num_normalize_higher;
    end
    if disp_factor(i,4)>= 140 && disp_factor(i,4)< 160 %emb3
        num_normalize_high = num_normalize_high + 1;
        total_nn_high = total_nn_high + disp_factor(i,4)*disp_factor(i,5);
        normalize_high = total_nn_high/num_normalize_high;
    end
    if disp_factor(i,4)>= 120 && disp_factor(i,4)< 140 %emb3
        num_normalize_highlow = num_normalize_highlow + 1;
        total_nn_highlow = total_nn_highlow + disp_factor(i,4)*disp_factor(i,5);
        normalize_highlow = total_nn_highlow/num_normalize_highlow;
    end
    if disp_factor(i,4)>= 100 && disp_factor(i,4)< 120 %emb3
        num_normalize_medhigh = num_normalize_medhigh + 1;
        total_nn_medhigh = total_nn_medhigh + disp_factor(i,4)*disp_factor(i,5);
        normalize_medhigh = total_nn_medhigh/num_normalize_medhigh;
    end
    if disp_factor(i,4)>= 80 && disp_factor(i,4)< 100 %emb3
        num_normalize_med = num_normalize_med + 1;
        total_nn_med = total_nn_med + disp_factor(i,4)*disp_factor(i,5);
        normalize_med = total_nn_med/num_normalize_med;
    end
    if disp_factor(i,4)>= 60 && disp_factor(i,4)< 80 %emb3
        num_normalize_medlow = num_normalize_medlow + 1;
        total_nn_medlow = total_nn_medlow + disp_factor(i,4)*disp_factor(i,5);
        normalize_medlow = total_nn_medlow/num_normalize_medlow;
    end
    if disp_factor(i,4)>= 40 && disp_factor(i,4)< 60 %emb3
        num_normalize_low = num_normalize_low + 1;
        total_nn_low = total_nn_low + disp_factor(i,4)*disp_factor(i,5);
        normalize_low = total_nn_low/num_normalize_low;
    end
    if disp_factor(i,4)>= 20 && disp_factor(i,4)< 40 %emb3
        num_normalize_lower = num_normalize_lower + 1;
        total_nn_lower = total_nn_lower + disp_factor(i,4)*disp_factor(i,5);
        normalize_lower = total_nn_lower/num_normalize_lower;
    end
    if disp_factor(i,4)>= 0 && disp_factor(i,4)< 20 %emb3
        num_normalize_lowest = num_normalize_lowest + 1;
        total_nn_lowest = total_nn_lowest + disp_factor(i,4)*disp_factor(i,5);
        normalize_lowest = total_nn_lowest/num_normalize_lowest;
    end
end

xaxis = [0 20 40 60 80 100 120 140 160 180 200]; %emb3, max is <160 thus 180 and 200 were removed, same as with yaxis
yaxis = [0 normalize_lowest normalize_lower normalize_low normalize_medlow normalize_med normalize_medhigh normalize_highlow normalize_high normalize_higher normalize_highest]; %emb3
plot(xaxis, yaxis);
title('Normalized Rate  vs. Intensity');
ylabel('Normalized Rate');
xlabel('Intensity'); 
hold on;

load ResultsEmb2.mat NPemb2 %important
disp_factor = NPemb2; %important
l_disp_factor = length(disp_factor);
count = 100;

%conventions: highest (180-200), higher (160-179), high (140-159), 
%highlow (120-139), medhigh (100-119), med (80-99), medlow (60-79),
%low (40-59), lower (20-39), lowest (0-19)
%for emb2, these are all divided by 2. So highest is 90-100 and so on.
num_normalize_highest = 0; 
num_normalize_higher = 0; 
num_normalize_high = 0; 
num_normalize_highlow = 0; 
num_normalize_medhigh = 0; 
num_normalize_med = 0; 
num_normalize_medlow = 0; 
num_normalize_low = 0; 
num_normalize_lower = 0; 
num_normalize_lowest = 0;
total_nn_highest = 0; 
total_nn_higher = 0; 
total_nn_high = 0; 
total_nn_highlow = 0; 
total_nn_medhigh = 0; 
total_nn_med = 0;
total_nn_medlow = 0;
total_nn_low = 0;
total_nn_lower = 0; 
total_nn_lowest = 0; 
normalize_highest = 0; 
normalize_higher = 0; 
normalize_high = 0; 
normalize_highlow = 0; 
normalize_medhigh = 0; 
normalize_med = 0; 
normalize_medlow = 0; 
normalize_low = 0; 
normalize_lower = 0;
normalize_lowest = 0;

for i = 1:l_disp_factor
    if disp_factor(i,4)>= 180 && disp_factor(i,4)< 200 %emb3
        num_normalize_highest = num_normalize_highest + 1;
        total_nn_highest = total_nn_highest + disp_factor(i,4)*disp_factor(i,5);
        normalize_highest = total_nn_highest/num_normalize_highest;
    end
    if disp_factor(i,4)>= 160 && disp_factor(i,4)< 180 %emb3
        num_normalize_higher = num_normalize_higher + 1;
        total_nn_higher = total_nn_higher + disp_factor(i,4)*disp_factor(i,5);
        normalize_higher = total_nn_higher/num_normalize_higher;
    end
    if disp_factor(i,4)>= 140 && disp_factor(i,4)< 160 %emb3
        num_normalize_high = num_normalize_high + 1;
        total_nn_high = total_nn_high + disp_factor(i,4)*disp_factor(i,5);
        normalize_high = total_nn_high/num_normalize_high;
    end
    if disp_factor(i,4)>= 120 && disp_factor(i,4)< 140 %emb3
        num_normalize_highlow = num_normalize_highlow + 1;
        total_nn_highlow = total_nn_highlow + disp_factor(i,4)*disp_factor(i,5);
        normalize_highlow = total_nn_highlow/num_normalize_highlow;
    end
    if disp_factor(i,4)>= 100 && disp_factor(i,4)< 120 %emb3
        num_normalize_medhigh = num_normalize_medhigh + 1;
        total_nn_medhigh = total_nn_medhigh + disp_factor(i,4)*disp_factor(i,5);
        normalize_medhigh = total_nn_medhigh/num_normalize_medhigh;
    end
    if disp_factor(i,4)>= 80 && disp_factor(i,4)< 100 %emb3
        num_normalize_med = num_normalize_med + 1;
        total_nn_med = total_nn_med + disp_factor(i,4)*disp_factor(i,5);
        normalize_med = total_nn_med/num_normalize_med;
    end
    if disp_factor(i,4)>= 60 && disp_factor(i,4)< 80 %emb3
        num_normalize_medlow = num_normalize_medlow + 1;
        total_nn_medlow = total_nn_medlow + disp_factor(i,4)*disp_factor(i,5);
        normalize_medlow = total_nn_medlow/num_normalize_medlow;
    end
    if disp_factor(i,4)>= 40 && disp_factor(i,4)< 60 %emb3
        num_normalize_low = num_normalize_low + 1;
        total_nn_low = total_nn_low + disp_factor(i,4)*disp_factor(i,5);
        normalize_low = total_nn_low/num_normalize_low;
    end
    if disp_factor(i,4)>= 20 && disp_factor(i,4)< 40 %emb3
        num_normalize_lower = num_normalize_lower + 1;
        total_nn_lower = total_nn_lower + disp_factor(i,4)*disp_factor(i,5);
        normalize_lower = total_nn_lower/num_normalize_lower;
    end
    if disp_factor(i,4)>= 0 && disp_factor(i,4)< 20 %emb3
        num_normalize_lowest = num_normalize_lowest + 1;
        total_nn_lowest = total_nn_lowest + disp_factor(i,4)*disp_factor(i,5);
        normalize_lowest = total_nn_lowest/num_normalize_lowest;
    end
end

xaxis = [0 20 40 60 80]; %emb3, max is <160 thus 180 and 200 were removed, same as with yaxis
yaxis = [0 normalize_lowest normalize_lower normalize_low normalize_medlow]; %emb3
plot(xaxis, yaxis);
hold on;

load ResultsEmb3.mat NPemb3 %important
disp_factor = NPemb3; %important
l_disp_factor = length(disp_factor);

%conventions: highest (180-200), higher (160-179), high (140-159), 
%highlow (120-139), medhigh (100-119), med (80-99), medlow (60-79),
%low (40-59), lower (20-39), lowest (0-19)
%for emb2, these are all divided by 2. So highest is 90-100 and so on.
num_normalize_highest = 0; 
num_normalize_higher = 0; 
num_normalize_high = 0; 
num_normalize_highlow = 0; 
num_normalize_medhigh = 0; 
num_normalize_med = 0; 
num_normalize_medlow = 0; 
num_normalize_low = 0; 
num_normalize_lower = 0; 
num_normalize_lowest = 0;
total_nn_highest = 0; 
total_nn_higher = 0; 
total_nn_high = 0; 
total_nn_highlow = 0; 
total_nn_medhigh = 0; 
total_nn_med = 0;
total_nn_medlow = 0;
total_nn_low = 0;
total_nn_lower = 0; 
total_nn_lowest = 0; 
normalize_highest = 0; 
normalize_higher = 0; 
normalize_high = 0; 
normalize_highlow = 0; 
normalize_medhigh = 0; 
normalize_med = 0; 
normalize_medlow = 0; 
normalize_low = 0; 
normalize_lower = 0;
normalize_lowest = 0;

for i = 1:l_disp_factor
    if disp_factor(i,4)>= 180 && disp_factor(i,4)< 200 %emb3
        num_normalize_highest = num_normalize_highest + 1;
        total_nn_highest = total_nn_highest + disp_factor(i,4)*disp_factor(i,5);
        normalize_highest = total_nn_highest/num_normalize_highest;
    end
    if disp_factor(i,4)>= 160 && disp_factor(i,4)< 180 %emb3
        num_normalize_higher = num_normalize_higher + 1;
        total_nn_higher = total_nn_higher + disp_factor(i,4)*disp_factor(i,5);
        normalize_higher = total_nn_higher/num_normalize_higher;
    end
    if disp_factor(i,4)>= 140 && disp_factor(i,4)< 160 %emb3
        num_normalize_high = num_normalize_high + 1;
        total_nn_high = total_nn_high + disp_factor(i,4)*disp_factor(i,5);
        normalize_high = total_nn_high/num_normalize_high;
    end
    if disp_factor(i,4)>= 120 && disp_factor(i,4)< 140 %emb3
        num_normalize_highlow = num_normalize_highlow + 1;
        total_nn_highlow = total_nn_highlow + disp_factor(i,4)*disp_factor(i,5);
        normalize_highlow = total_nn_highlow/num_normalize_highlow;
    end
    if disp_factor(i,4)>= 100 && disp_factor(i,4)< 120 %emb3
        num_normalize_medhigh = num_normalize_medhigh + 1;
        total_nn_medhigh = total_nn_medhigh + disp_factor(i,4)*disp_factor(i,5);
        normalize_medhigh = total_nn_medhigh/num_normalize_medhigh;
    end
    if disp_factor(i,4)>= 80 && disp_factor(i,4)< 100 %emb3
        num_normalize_med = num_normalize_med + 1;
        total_nn_med = total_nn_med + disp_factor(i,4)*disp_factor(i,5);
        normalize_med = total_nn_med/num_normalize_med;
    end
    if disp_factor(i,4)>= 60 && disp_factor(i,4)< 80 %emb3
        num_normalize_medlow = num_normalize_medlow + 1;
        total_nn_medlow = total_nn_medlow + disp_factor(i,4)*disp_factor(i,5);
        normalize_medlow = total_nn_medlow/num_normalize_medlow;
    end
    if disp_factor(i,4)>= 40 && disp_factor(i,4)< 60 %emb3
        num_normalize_low = num_normalize_low + 1;
        total_nn_low = total_nn_low + disp_factor(i,4)*disp_factor(i,5);
        normalize_low = total_nn_low/num_normalize_low;
    end
    if disp_factor(i,4)>= 20 && disp_factor(i,4)< 40 %emb3
        num_normalize_lower = num_normalize_lower + 1;
        total_nn_lower = total_nn_lower + disp_factor(i,4)*disp_factor(i,5);
        normalize_lower = total_nn_lower/num_normalize_lower;
    end
    if disp_factor(i,4)>= 0 && disp_factor(i,4)< 20 %emb3
        num_normalize_lowest = num_normalize_lowest + 1;
        total_nn_lowest = total_nn_lowest + disp_factor(i,4)*disp_factor(i,5);
        normalize_lowest = total_nn_lowest/num_normalize_lowest;
    end
end

xaxis = [0 20 40 60 80 100 120 140 160]; %emb3, max is <160 thus 180 and 200 were removed, same as with yaxis
yaxis = [0 normalize_lowest normalize_lower normalize_low normalize_medlow normalize_med normalize_medhigh normalize_highlow normalize_high]; %emb3
plot(xaxis, yaxis);
legend('Embryo 1','Embryo 2','Embryo 3','Location','northwest');
savefig('PlotNormalizeEmb1All23.fig'); %important
save('NormalizeEmb1All23.mat'); %important
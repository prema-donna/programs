clc 
clear
%At the end NPemb mat has: NPpositionX, NppositionY, Npposition Z, FI,
%TAWSS, PositionX, Position Y, Position Z

%Load tawss and NP mat
load tawss_emb3;
load NPemb3;
lNP=length(NPemb3);

%Change position units from mm to m
NPemb3(:,1:3)=NPemb3(:,1:3)*0.001;

% %Max X position for tawss matrix
% maxxtawss=max(tawss(:,1));
% %Extrusion vessel in m
% extrX=3.5e-5;
% %Diference to calculate the starting X position
% startX=maxxtawss-extrX;
% 
% toDelete = (startX < tawss(:,1));
% tawss(toDelete, :) = [];

row1=zeros(lNP,5);
NPemb3=[NPemb3 row1];
tempmat=zeros(length(tawss),1);
tolx=(max(tawss(:,1))-min(tawss(:,1)))/102;
% toly=(max(tawss(:,2))-min(tawss(:,2)))/5;
% tolz=(max(tawss(:,3))-min(tawss(:,3)))/4;
%Results=zeros(lNP,2);


for j=1:lNP
    NPx=NPemb3(j,1);
    NPy=NPemb3(j,2);
    NPz=NPemb3(j,3);
    
    for k=1:length(tawss)
        if tolx>abs(NPx-tawss(k,1)) %&& toly>abs(NPy-tawss(k,2)) && tolz>abs(NPz-tawss(k,3))
        tempmat(k,1)=sqrt((NPx-tawss(k,1))^2+(NPy-tawss(k,2))^2+(NPz-tawss(k,3))^2);
        end
    end
    
    tempmat(tempmat==0) = inf;
    [M,I]=min(tempmat);
    %CHANGE TO 5 IF NPemb2 OR NPemb3
    NPemb3(j,5)=tawss(I,4);
    NPemb3(j,6)=tawss(I,1);
    NPemb3(j,7)=tawss(I,2);
    NPemb3(j,8)=tawss(I,3);
    NPemb3(j,9)=M;
    tempmat=zeros(length(tawss),1);
end


save('PairingTAWSSResults_emb3','NPemb3');
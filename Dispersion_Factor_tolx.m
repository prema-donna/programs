%clc 
%clear all

%Script calculates the dispersion factor for each value in the flow  

load Mat_disp_fact.mat vel_part4
vel=vel_part4;
clear Mat_disp_fact.mat vel_part4;
lVel=length(vel);
%Matrix for vel has columns for: x, y, z, velocity magnitude, x
%velocity, y velocity, z velocity

%NP matrix has 4 columns: x position, y position, z position, fluorescence
%intensity
load Mat_disp_fact.mat NPemb1_part4
NPemb1=NPemb1_part4;
clear Mat_disp_fact.mat NPemb1_part4;
lNP=length(NPemb1);

%Change position units from mm to m
NPemb1(:,1:3)=NPemb1(:,1:3)*0.001;

%Max X position for vel matrix
maxxvel=max(vel(:,1));
%Extrusion vessel in m
extrX=4.01e-5;
%Difference to calculate the starting X position
startX=maxxvel-extrX;

toDelete = (startX < vel(:,2));
vel(toDelete, :) = [];

lVel=length(vel);
mat1=zeros(lVel,2);
vel=[vel mat1];

for i=1:lVel
%     Vx=vel(i,6);
%     Vy=vel(i,7);
%     Vz=vel(i,8);
  
    vel(i,8)=sqrt((vel(i,7)^2)+(vel(i,6)^2));
    vel(i,9)=abs(sqrt((vel(i,7)^2)+(vel(i,6)^2))/vel(i,5));
end

row1=zeros(lNP,4);
NPemb1=[NPemb1 row1];
tempmat=zeros(lVel,1);
tolx=8e-7;%(max(vel(:,1))-min(vel(:,1)))/200;
toly=(max(vel(:,2))-min(vel(:,2)))/4;
tolz=(max(vel(:,3))-min(vel(:,3)))/4;
% Results=zeros(lNP,2);

for j=1:lNP
    NPx=NPemb1(j,1);
    NPy=NPemb1(j,2);
    NPz=NPemb1(j,3);
    
    for k=1:lVel
        if tolx>abs(NPx-vel(k,1)) %&& toly>abs(NPy-vel(k,2)) %&& tolz>abs(NPz-vel(k,3))
            tempmat(k,1)=sqrt((NPx-vel(k,1))^2+(NPy-vel(k,2))^2+(NPz-vel(k,3))^2);
        end
            
    end

    tempmat(tempmat==0) = inf;
    [M,I]=min(tempmat);
    NPemb1(j,5)=vel(I,9);
    NPemb1(j,6)=vel(I,1);
    NPemb1(j,7)=vel(I,2);
    NPemb1(j,8)=vel(I,3);
    %tempmat=zeros(lVel,4);
end

save('ResultsEmb1_Part4','NPemb1');
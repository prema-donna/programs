clc
clear

n=0.1;
range=[n:n:1]';
lrange=length(range);

resp=zeros(lrange+1,6);
resp(1:lrange,1)=range;

load NPemb2;
lNP= length(NPemb2);

for i=1:lNP;
    df=NPemb2(i,5);
    FI=NPemb2(i,4);
    if df<resp(1,1)
        resp(1,2)=resp(1,2)+1;
        resp(1,3)=resp(1,3)+FI;
    elseif df>resp(lrange,1)
         resp(lrange+1,2)=resp(lrange+1,2)+1;
         resp(lrange+1,3)=resp(lrange+1,3)+FI;
    else    
    for j=2:lrange;
        if df>resp(j-1,1)&& df<resp(j,1)
            resp(j,2)=resp(j,2)+1;
            resp(j,3)=resp(j,3)+FI;
        end
    end
    end
end

load velemb2
lvel=length(vel);


for i=1:lvel;
    dfval=vel(i,10);
    if dfval<resp(1,1)
        resp(1,4)=resp(1,4)+1;
    elseif dfval>resp(lrange,1)
         resp(lrange+1,4)=resp(lrange+1,4)+1;
    else    
    for j=2:lrange;
        if dfval>resp(j-1,1)&& dfval<resp(j,1)
            resp(j,4)=resp(j,4)+1;
        end
    end
    end
end

resp(:,5)=resp(:,2)./resp(:,4);
resp(:,6)=resp(:,3)./resp(:,4);

%Plot results
bar(resp(:,1),resp(:,end))
xlabel('Dispersion Factor)');
ylabel('Fluorescence intensity per vessel wall voxels')
xlim([0 1])
box off



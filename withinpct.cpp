#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>

using namespace std;

bool areWithinPct(double pct, double *item, int size){
  double largest = INT_MIN;
  double smallest = INT_MAX;
  for(int i= 0; i<size; i++){
  	if(item[i] < smallest){
    	smallest = item[i];
    }
    if(item[i] > largest){
    	largest = item[i];
    }
  }
  cout<<"largest: "<<largest<<endl;
  cout<<"smallest: "<<smallest<<endl;
  
  double difference = (abs(largest-smallest)/smallest)*100;
  
  if (difference <= pct) return true;
  
  return false;
}

int main(){
	int size = 10;
	double item[10] = {104,100,101,102,103,104,108,109,111,105};
	double pct = 10;
	
	if(areWithinPct(pct,item,size) == false) cout<<"Items are NOT within "<<pct<<"% of one another"<<endl;
	else{
		cout<<"Items ARE within "<<pct<<"% of one another"<<endl;
	}
	
	return 0;
}
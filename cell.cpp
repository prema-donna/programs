#include<iostream>
#include<cstdlib>
#include<vector>

using namespace std;

vector<int> cellCompete(int* states, int days) 
{
    // WRITE YOUR CODE HERE
    int edge_adjacent = 0;
    int day_count = days;
    vector<int> cell;
    vector<int> original;
    
    for(int i= 0; i<sizeof(states); i++){
        cell.push_back(states[i]);   
        original.push_back(states[i]);
    }
    
    while(day_count >0){ 
        for(int i= 0; i<original.size(); i++){
            int h = i-1;
            int j = i+1;
            if (i == 0){
                if(original[j] != edge_adjacent){
                    cell[i] = 1;
                }
                else{
                    cell[i] = 0;
                }
            }
            else if(i == original.size()-1){
                if(original[h] != edge_adjacent){
                    cell[i] = 1;
                }
                else{
                    cell[i] = 0;
                }
            }
            else{
                if(original[h] != original[j]){
                    cell[i] = 1;
                }
                else{
                    cell[i] = 0;
                }
            }
        }
        day_count--;
        original = cell;
    }
    return cell;
}

void print_array(int* array){
	cout<<"Original cell array: ";
	for(int i= 0; i<sizeof(array); i++){
		cout<<array[i]<<",";
	}
	cout<<"\n";
}

void print_vector(vector<int> vec, int days){
	cout<<"Cell array, after "<<days<<" days: ";
	for(int i= 0; i<vec.size()-1; i++){
		cout<<vec[i]<<",";
	}
	cout<<vec[vec.size()-1]<<"\n";
}

int main(){
	int states[] = {1,0,1,0,0,1,0,1};
	print_array(states);
	int days = 2;
	print_vector(cellCompete(states,days),days);
	
	int states2[] = {0,0,1,0,1,1,0,1};
	print_array(states2);
	days = 1;
	print_vector(cellCompete(states2,days),days);
	
	return 0;
}
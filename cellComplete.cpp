#include<iostream>
#include<cstdlib>

using namespace std;

vector<int> cellCompete(int* states, int days) 
{
    vector<int> prevCell(sizeof(states));
    vector<int> cell(sizeof(states));
    for(int i= 0; i< sizeof(states); i++){
        prevCell[i] = states[i];
    }
    cell = prevCell;
    while(days > 0){
        for(int i= 0; i< prevCell.size(); i++){
            int j = i+1;
            int h = i-1;
            if(i == 0){
                if(prevCell[j] == 0) cell[i] = 0;
                else cell[i] = 1;
            }
            else if(i == prevCell.size()-1){
                if(prevCell[h] == 0) cell[i] = 0;
                else cell[i] = 1;
            }
            else{
                if(prevCell[h] == prevCell[j]) cell[i] = 0;
                else cell[i] = 1;
            }
        }
        days--;
        prevCell = cell;
    }
    return cell;
}
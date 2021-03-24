#include<iostream>
#include<vector>

using namespace std;

vector<int> cellCompete(int* states, int days) 
{
    // WRITE YOUR CODE HERE
    vector<int> currState;
    for(int i = 0; i< sizeof(states); i++)
    {
        currState.push_back(states[i]);
    }
    for(int i= 1; i<= days; i++)
    {
        vector<int> prevState = currState;
        int prev;
        int next;
        for(int i= 0; i< prevState.size(); i++){
            if(i-1 < 0) prev = 0;
            else prev = prevState[i-1];
            if(i == prevState.size()-1) next = 0;
            else next = prevState[i+1];
            if(prev == next) currState[i] = 0;
            else currState[i] = 1;
        }
    }
    
    return currState;
}
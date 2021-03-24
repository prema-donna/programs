#include<iostream>
#include<cstdlib>

using namespace std;

int generalizedGCD(int num, int* arr)
{
    // WRITE YOUR CODE HERE  
    int largest = 0;
    for(int i= 0; i< num; i++){
        if(arr[i] > largest) largest = arr[i];
    }
    int gcd = largest;
    int matches = 0;
    while(gcd > 1){
        for(int i = 0; i< num; i++){
            if(arr[i]%gcd != 0) break;
            else matches++;
        }
        if(matches == num) return gcd;
        matches = 0;
        gcd--;
    }
    return 1;
}
#include<iostream>

int generalizedGCD(int num, int* arr)
{
    // WRITE YOUR CODE HERE
    int largest = -1;
    for(int i= 0; i< num; i++)
    {
        if(arr[i] > largest) largest = arr[i];
    }
    while(largest > 1)
    {
        int good_count = 0;
        for(int i= 0; i< num; i++)
        {
            if(arr[i] % largest == 0) good_count++;
        }
        if(good_count == num) return largest;
        else largest--;
    }
    return 1;
}
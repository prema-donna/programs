#include <stdexcept>
#include <iostream>
#include <vector>

int findMaxSum(const std::vector<int>& numbers)
{
    int largestNumber = -1;
    int secondLargestNumber = -1;
    for(int i= 0; i< numbers.size(); i++)
    {
        if(numbers[i] > largestNumber)
        {
            secondLargestNumber = largestNumber;
            largestNumber = numbers[i];
        }
        else if(numbers[i] > secondLargestNumber)
        {
            secondLargestNumber = numbers[i];
        }
    }
    return largestNumber+secondLargestNumber;
}

#ifndef RunTests
int main()
{
    std::vector<int> v { 5, 9, 7, 11 };
    std::cout << findMaxSum(v);
}
#endif
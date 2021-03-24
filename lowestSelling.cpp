#include<vector>
#include<unordered_map>
#include<stdexcept>
#include<iostream>

int nthLowestSelling(const std::vector<int>& sales, int n) 
{
    std::unordered_map<int,int> counts;
    for(int i= 0; i< sales.size(); i++)
    {
        counts[sales[i]]++;
    }

    int lowestSelling;
    int index = 0;
    while(index < n)
    {
		int lowestSales = sales.size()+1;
        for(std::unordered_map<int,int>::iterator it=counts.begin(); it!=counts.end(); it++)
        {
            if(lowestSales > it->second){
                lowestSales = it->second;
                lowestSelling = it->first;
            }
        }
        counts[lowestSelling] = sales.size()+1;
		index++;
    }
    return lowestSelling;
}

int main()
{
    std::vector<int> input;
    input.push_back(5);
    input.push_back(4);
    input.push_back(3);
    input.push_back(2);
    input.push_back(1);
    input.push_back(5);
    input.push_back(4);
    input.push_back(3);
    input.push_back(2);
    input.push_back(5);
    input.push_back(4);
    input.push_back(3);
    input.push_back(5);
    input.push_back(4);
    input.push_back(5);
    int x = nthLowestSelling(input, 2);
    std::cout << x;
}
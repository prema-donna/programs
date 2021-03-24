#include<iostream>
#include<unordered_map>
#include<string>
#include<climits>
#include<vector>

using namespace std;

string returnNthLowestBook(unordered_map<string,double> allBooks, int n)
{
	vector<string> sortedBooks;
	int cheapest = INT_MAX;
	string cheapestRemainingBook;
	int index = 0;
	while(index < n)
	{
		for(unordered_map<string,double>::iterator it = allBooks.begin(); it != allBooks.end(); it++)
		{
			if(it->second < cheapest)
			{
				cheapest = it->second;
				cheapestRemainingBook = it->first;
			}
		}
		sortedBooks.push_back(cheapestRemainingBook);
		allBooks[cheapestRemainingBook] = INT_MAX;
		cheapest = INT_MAX;
		index++;
	}

	return cheapestRemainingBook; 
}

int main()
{
	unordered_map<string,double> allBooks = {{"LOTR", 15.55},{"Hobbit", 12.98},
		{"War and Peace", 22.23},{"Anna Karenina", 19.18},
		{"Hunt for Red October", 9.95},{"The Wind in the Willows", 5.50},
		{"Don Quixote", 16.19}};
	int numLowest = 2;
	cout<<"The "<<numLowest<<"th cheapest book is "<<returnNthLowestBook(allBooks,numLowest)<<endl;
	cout<<"Cost: "<<allBooks[returnNthLowestBook(allBooks,numLowest)]<<endl;
	
	return 0;
}
	
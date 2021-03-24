#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<vector>
#include<string>
#include<map>

using namespace std;

struct historicalQuotes{
	string name;
	vector<double> monthlyQuotes;
	vector<double> momGains;
	map<int,vector<double>> mapQuotes;
	map<int,vector<double>> mapGains;
};

void calculateMomGains(historicalQuotes company, vector<double> monthlyQuotes)
{
	vector<double> momGains;
	for(int i= 1; i< monthlyQuotes.size(); i++)
	{
		double prevMonth = monthlyQuotes[i-1];
		double currMonth = monthlyQuotes[i];
		momGains.push_back(100*(currMonth-prevMonth)/prevMonth);
	}
	company.momGains = momGains;
}

void setUpStruct(historicalQuotes company, string name, vector<double> monthlyQuotes)
{
	company.name = name;
	company.monthlyQuotes = monthlyQuotes;
	calculateMomGains(company, company.monthlyQuotes);
}

void setUpMap(historicalQuotes company, vector<double> monthlyQuotes,int count)
{
	int year = 2016;
	map<int,vector<double>> mapQuotes;
	for(int i= 0; i< monthlyQuotes.size(); i+=12)
	{
		vector<double> yearly(12);
		int index = 0;
		for(int j = i; j < i+12 && j<monthlyQuotes.size(); j++)
		{
			yearly[index] = monthlyQuotes[j];
			index++;
		}
		mapQuotes[year] = yearly;
		year++;
	}
	if(count == 1) company.mapQuotes = mapQuotes;
	else{company.mapGains = mapQuotes;}
}

void printToScreen(string name, map<int,vector<double>> mapQuotes, map<int,vector<double>> mapGains, string months[12])
{
	cout<<"Company name: "<<name<<" "<<mapQuotes.size()<<endl;
	int year = 2016;
	for(auto it = mapQuotes.cbegin(), end_it = mapQuotes.cend(), 
		it2 = mapGains.cbegin(), end_it2 = mapGains.cend(); 
		it != end_it || it2 != end_it2;)
	{
		for(int i = 0; i< it->second.size(); i++)
		{
			if(year != 2016 && i != 0)
			{
				cout<<months[i]<<" "<< year <<": "<< it->second[i] <<", MoM gains: "<< it2->second[i] <<endl;
				if(i == 11 && year != 2020)
				{
					i = 0;
					year++;
				}
			}
			else cout<<months[0]<<" "<<year<<": "<< it->second[i] <<endl;
		}
	}
}

int main()
{
	historicalQuotes amzn;
	historicalQuotes msft;
	historicalQuotes adbe;
	historicalQuotes fb;
	historicalQuotes nvda;
	historicalQuotes csco;
	historicalQuotes avgo;
	historicalQuotes v;
	historicalQuotes ma;
	
	string amazon = "Amazon";
	
	string months[12] = {"January","February","March","April","May","June","July",
					"August","September","October","November","December"};
	vector<double> amznVal = {656.29,578.15,556.29,590.49,663.92,720.90,717.32,
				759.87,770.90,836.00,799.00,752.41,757.92,829.21,853.05,888.00,
				927.80,998.59,972.79,996.11,984.20,964.00,1105.40,1172.05,
				1172.00,1445.00,1513.60,1417.62,1563.22,1637.03,1682.70,1784.00,
				2026.50,2021.99,1623.53,1769.46,1465.20,1638.88,1655.13,1800.11,
				1933.09,1760.01,1922.98,1871.72,1770.00,1746.00,1788.01,1804.40,
				1875.00,2010.60,1906.49,1932.97,2372.33};
	
	setUpStruct(amzn,amazon,amznVal);
	setUpMap(amzn,amznVal,1);
	setUpMap(amzn,amzn.momGains,2);
	printToScreen(amazon,amzn.mapQuotes,amzn.mapGains,months);
	
	return 0;
}
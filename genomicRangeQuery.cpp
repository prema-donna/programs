#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include<unordered_map>
#include<climits>

using namespace std;

vector<int> genQuery(string &s, vector<int> &p, vector<int> &q)
{
	vector<int> impactFactors;
	unordered_map<char,int> if_mapper;
	if_mapper['A'] = 1;
	if_mapper['C'] = 2;
	if_mapper['G'] = 3;
	if_mapper['T'] = 4;
	
	for(int i= 0; i< p.size(); i++)
	{
		int size = q[i]-p[i]+1;
		string sub = s.substr(p[i],size);
		int currImpact = INT_MAX;
		for(int j= 0; j< sub.length(); j++)
		{
			if(if_mapper[sub[j]] < INT_MAX) currImpact = if_mapper[sub[j]];
		}
		impactFactors.push_back(currImpact);
	}
	return impactFactors;
}

void print(vector<int> impactFactors)
{
	for(int i= 0; i< impactFactors.size(); i++)
	{
		cout<<impactFactors[i]<<", ";
	}
	cout<<endl;
}

int main()
{
	string s = "CAGCCTA";
	vector<int> p = {2,5,0};
	vector<int> q = {4,5,6};
	vector<int> impactFactors = genQuery(s,p,q);
	
	cout<<"List of impact factors for all bases in DNA: ";
	print(impactFactors);
	
	return 0;
}
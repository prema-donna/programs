#include<iostream>
#include<cstdlib>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

/* # There are a total of n courses you have to take, labeled from 0 to n-1.
# Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
# Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.
# There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

# Example 1:
# Input: 2, [[1,0]] 
# Output: [0,1]
# Explanation: There are a total of 2 courses to take. To take course 1 you should have finished   
#              course 0. So the correct course order is [0,1] .

# Example 2:
# Input: 4, [[1,0],[2,0],[3,1],[3,2]]
# Output: [0,1,2,3] or [0,2,1,3]
# Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both     
#              courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. 
#              So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3] . */

vector<int> findOrder(int numCourses, vector<vector<int>> prerequisites)
{
	vector<int> solution;
	map<int,vector<int>> graph;
	for(int i= 0; i< numCourses; i++)
	{
		vector<int> midv;
		for(int j= 0; j< prerequisites.size(); j++)
		{
			if(prerequisites[j][0] == i) midv.push_back(prerequisites[j][1]);
		}
		graph[i] = midv;
	}
	for(map<int,vector<int>>::iterator it = graph.begin(); it != graph.end(); ++it)
	{
		cout<<"Pre-reqs for course "<<it->first<<" ";
		for(int i= 0; i< it->second.size(); i++)
		{
			cout<<it->second[i]<<", ";
		}
		cout<<endl;
		if(it->second.size() == 0) solution.push_back(it->first);
	}
	if(solution.size() == 0) return solution;
	while(solution.size() < numCourses)
	{
		for(int i= 0; i< solution.size(); i++)
		{
			for(int j= 0; j< prerequisites.size(); j++)
			{
				if(solution[i] == prerequisites[j][1] && count(solution.begin(),solution.end(),prerequisites[j][0]) == 0)
				{
					solution.push_back(prerequisites[j][0]);
				}	
			}
		}
	}
	return solution;
}

int main()
{
	vector<vector<int>> prereqs = {{1,0},{2,0},{3,1},{3,2}};
	int size = 4;
	cout<<"Order of courses: ";
	vector<int> solution = findOrder(size,prereqs);
	for(int i= 0; i< solution.size(); i++)
	{
		cout<<solution[i]<<", ";
	}
	cout<<endl;
	return 0;
}
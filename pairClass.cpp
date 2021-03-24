#include<iostream>
#include<vector>

using namespace std;

//Pair class that encapsulates the pair, protecting the first and second numbers of the pair
//The pair can only be set using the setter, and each number can only be fetched using its getter
class Pair{
	private:
		int first;
		int second;
	public:
		Pair(){
			first = 0;
			second = 0;
		}
		void set(int a, int b){
			first = a;
			second = b;
		}
		int get_first(){
			return first;
		}
		int get_second(){
			return second;
		}
};

//Utility class with two private vectors, one for the original list, and the other for the pairs
class Utility : Pair{
	private:
		vector<int> numbers;
		vector<pair<int,int>> pairs;
	public:
		//initializes the private vectors with the user-defined list
		//technically pairs does not need to be initializes as it's empty
		Utility(vector<int> a, vector<pair<int,int>> b){
			numbers = a;
			pairs = b;
		}
		//isEqualTen is the most important function, it checks to see if 2 elements are equal to 10
		//then it uses a Pair class object to set the values of first and second in the Pair class
		//and finally, it populates the pairs vector with the first and second values using getters
		void isEqualTen(vector<int> a){
			Pair p;
			for (int i= 0; i<a.size(); i++){
				for (int j= i+1; j<a.size(); j++){
					if ((a[i]+a[j]) == 10){
						p.set(a[i],a[j]);
						pairs.push_back(make_pair(p.get_first(),p.get_second()));
					}
				}				
			}
		}
		//I used this as a getter, but it's unnecessary 
		vector<pair<int,int>> get_pairs(){
			return pairs;
		}
		//prints pairs using the described format
		void format_pairs(){
			vector<pair<int,int>> a = get_pairs();
			cout<<"\"";
			for (int i=0; i<a.size(); i++){
				cout<<"("<<a[i].first<<","<<a[i].second<<")";
				if (i != a.size()-1) cout<<", ";
			}
			cout<<"\"";
		}
}; 

int main(){
	//the main assumption that I make is that I am not asked to write a parser
	vector<int> nums;
	vector<pair<int,int>> pair_nums;
	nums.push_back(1);
	nums.push_back(8);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(5);
	nums.push_back(7);
	
	//creating a Utility object to populate the list, determine the pairs, & print plus format the pairs
	Utility object(nums,pair_nums);
	object.isEqualTen(nums);
	object.format_pairs();
	
	return 0;
}

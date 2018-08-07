#include<iostream>
#include<cstdlib>
#include<vector>
#include<string>

using namespace std;

class Hitter{
	private:
		vector<string> categories;
	public:
		void add_hit(string category){
			string cat = category;
			for (int i= 0; i<categories.size(); i++){
				if (cat == categories[i] || cat == "R" && categories[i] == "RUN" || cat == "RUN" && categories[i] == "R" || cat == "SO" && categories[i] == "K" ||
					cat == "K" && categories[i] == "SO"){
						cout<< "You've already entered that category!\n";
						return;
				}
			}
			if(cat == "R" || cat == "RUN" || cat == "1B" || cat == "2B" || cat == "3B" || cat == "HR" || cat == "RBI" || cat == "BB" || cat == "K" || cat == "SB" ||
			   cat == "SH" || cat == "GS" || cat == "SO") 
				categories.push_back(cat);
			else{
				cout<<"Invalid category!\n";
			}
		}
		void prompt(){
			while(1){
				string cat;
				cout<<"Add a valid MLB hitting category (3 char limit, UPPERCASE), type Q when finished\n";
				cin>>cat;
				if (cat == "Q") break;
				if (cat.length() <= 3){
					add_hit(cat);
				}
				else{
					cout<<"Too many letters!\n";
				}
			}
		}
		vector<string> get_cats(){
			return categories;
		}
		void print_all_categories(){
			vector<string> cats = get_cats();
			int count = 0;
			for(int i= 0; i< cats.size(); i++){
				if(cats[i] == "R"){
					categories[count] = cats[i];
					++count;
					cout<<"   "<<cats[i];
				}
				if(cats[i] == "RUN"){
					categories[count] = cats[i];
					++count;
					cout<<" "<<cats[i];
				}
			}
			for(int i= 0; i<cats.size(); i++){
				if(cats[i] == "1B"){
					categories[count] = cats[i];
					++count;
					cout<<"  "<<cats[i];
				}
			}
			for(int i= 0; i<cats.size(); i++){
				if(cats[i] == "2B"){
					categories[count] = cats[i];
					++count;
					cout<<"  "<<cats[i];
				}
			}
			for(int i= 0; i<cats.size(); i++){
				if(cats[i] == "3B"){
					categories[count] = cats[i];
					++count;
					cout<<"  "<<cats[i];
				}
			}
			for(int i= 0; i<cats.size(); i++){
				if(cats[i] == "HR"){
					categories[count] = cats[i];
					++count;
					cout<<"  "<<cats[i];
				}
			}
			for(int i= 0; i<cats.size(); i++){
				if(cats[i] == "RBI"){
					categories[count] = cats[i];
					++count;
					cout<<" "<<cats[i];
				}
			}
			for(int i= 0; i<cats.size(); i++){
				if(cats[i] == "SH"){
					categories[count] = cats[i];
					++count;
					cout<<"  "<<cats[i];
				}
			}
			for(int i= 0; i<cats.size(); i++){
				if(cats[i] == "SB"){
					categories[count] = cats[i];
					++count;
					cout<<"  "<<cats[i];
				}
			}
			for(int i= 0; i<cats.size(); i++){
				if(cats[i] == "BB"){
					categories[count] = cats[i];
					++count;
					cout<<"  "<<cats[i];
				}
			}
			for(int i= 0; i<cats.size(); i++){
				if(cats[i] == "K"){
					categories[count] = cats[i];
					++count;
					cout<<"   "<<cats[i];
				}
				if(cats[i] == "SO"){
					categories[count] = cats[i];
					++count;
					cout<<"  "<<cats[i];
				}
			}
			for(int i= 0; i<cats.size(); i++){
				if(cats[i] == "GS"){
					categories[count] = cats[i];
					++count;
					cout<<"  "<<cats[i];
				}
			}
			cout<<"\n";
		}
};

class Pitcher{
	private:
		vector<string> categories;
	public:
		void add_pitch(string category){
			string cat = category;
			for (int i= 0; i<categories.size(); i++){
				if (cat == categories[i] || cat == "W" && categories[i] == "WIN" || cat == "WIN" && categories[i] == "W" || cat == "H" && categories[i] == "HIT" ||
					cat == "HIT" && categories[i] == "H" || cat == "SO" && categories[i] == "K" || cat == "K" && categories[i] == "SO"){
						cout<< "You've already entered that category!\n";
						return;
				}
			}
			if(cat == "W" || cat == "WIN" || cat == "SV" || cat == "HLD" || cat == "K" || cat == "BB" || cat == "H" || cat == "HIT" || cat == "QS" || cat == "IP" ||
			   cat == "ER" || cat == "CG" || cat == "SHO" || cat == "RW" || cat == "SO") 
				categories.push_back(cat);
			else {
				cout<<"Invalid category!\n";
			}
		}
		void prompt(){
			while(1){
				string cat;
				cout<<"Add a valid MLB pitching category (3 char limit, UPPERCASE), type Q when finished\n";
				cin>>cat;
				if (cat == "Q") break;
				if (cat.length() <= 3){
					add_pitch(cat);
				}
				else{
					cout<<"Too many letters!\n";
				}
			}
		}
		vector<string> get_cats(){
			return categories;
		}
		void print_all_categories(){
			vector<string> cats = get_cats();
			int count = 0;
			for(int i= 0; i<cats.size(); i++){
				if(cats[i] == "IP"){
					categories[count] = cats[i];
					++count;
					cout<<"  "<<cats[i];
				}
			}
			for(int i= 0; i< cats.size(); i++){
				if(cats[i] == "W"){
					categories[count] = cats[i];
					++count;
					cout<<"   "<<cats[i];
				}
				if(cats[i] == "WIN"){
					categories[count] = cats[i];
					++count;
					cout<<" "<<cats[i];
				}
			}
			for(int i= 0; i<cats.size(); i++){
				if(cats[i] == "CG"){
					categories[count] = cats[i];
					++count;
					cout<<"  "<<cats[i];
				}
			}
			for(int i= 0; i<cats.size(); i++){
				if(cats[i] == "SHO"){
					categories[count] = cats[i];
					++count;
					cout<<" "<<cats[i];
				}
			}
			for(int i= 0; i<cats.size(); i++){
				if(cats[i] == "SV"){
					categories[count] = cats[i];
					++count;
					cout<<"  "<<cats[i];
				}
			}
			for(int i= 0; i<cats.size(); i++){
				if(cats[i] == "H"){
					categories[count] = cats[i];
					++count;
					cout<<"   "<<cats[i];
				}
				if(cats[i] == "HIT"){
					categories[count] = cats[i];
					++count;
					cout<<" "<<cats[i];
				}
			}
			for(int i= 0; i<cats.size(); i++){
				if(cats[i] == "ER"){
					categories[count] = cats[i];
					++count;
					cout<<"  "<<cats[i];
				}
			}
			for(int i= 0; i<cats.size(); i++){
				if(cats[i] == "BB"){
					categories[count] = cats[i];
					++count;
					cout<<"  "<<cats[i];
				}
			}
			for(int i= 0; i<cats.size(); i++){
				if(cats[i] == "K"){
					categories[count] = cats[i];
					++count;
					cout<<"   "<<cats[i];
				}
				if(cats[i] == "SO"){
					categories[count] = cats[i];
					++count;
					cout<<"  "<<cats[i];
				}
			}
			for(int i= 0; i<cats.size(); i++){
				if(cats[i] == "HLD"){
					categories[count] = cats[i];
					++count;
					cout<<" "<<cats[i];
				}
			}
			for(int i= 0; i<cats.size(); i++){
				if(cats[i] == "RW"){
					categories[count] = cats[i];
					++count;
					cout<<"  "<<cats[i];
				}
			}
			for(int i= 0; i<cats.size(); i++){
				if(cats[i] == "QS"){
					categories[count] = cats[i];
					++count;
					cout<<"  "<<cats[i];
				}
			}
			cout<<"\n";
		}
};

int main(){
	Hitter h;
	h.prompt();
	h.print_all_categories();
	
	Pitcher p;
	p.prompt();
	p.print_all_categories();
	
	return 0;
}
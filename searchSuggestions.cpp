#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'searchSuggestions' function below.
 *
 * The function is expected to return a 2D_STRING_ARRAY.
 * The function accepts following parameters:
 *  1. STRING_ARRAY repository
 *  2. STRING customerQuery
 */

vector<vector<string>> searchSuggestions(vector<string> repository, string customerQuery) {
    for(int i= 0; i< customerQuery.length(); i++) customerQuery[i] = tolower(customerQuery[i]);
    multiset<string> sortedStrings;
    string prefix(1, customerQuery[0]);
    for(int i= 0; i< repository.size(); i++){
        for(int j= 0; j< repository[i].length(); j++) repository[i][j] = tolower(repository[i][j]);
        sortedStrings.insert(repository[i]);
    }
    vector<vector<string>> suggestions;
    while(prefix.length() < customerQuery.length()){
        prefix += customerQuery[prefix.length()];
        vector<string> subSuggestions;
        int num_iters = 0;
        for(set<string>::iterator it = sortedStrings.begin(); it != sortedStrings.end(); ++it){
            if((*it).substr(0,prefix.length()) == prefix && num_iters < 3){
                subSuggestions.push_back(*it);
                num_iters++;
            }
        }
        suggestions.push_back(subSuggestions);
    }
    return suggestions;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string repository_count_temp;
    getline(cin, repository_count_temp);

    int repository_count = stoi(ltrim(rtrim(repository_count_temp)));

    vector<string> repository(repository_count);

    for (int i = 0; i < repository_count; i++) {
        string repository_item;
        getline(cin, repository_item);

        repository[i] = repository_item;
    }

    string customerQuery;
    getline(cin, customerQuery);

    vector<vector<string>> result = searchSuggestions(repository, customerQuery);

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            fout << result[i][j];

            if (j != result[i].size() - 1) {
                fout << " ";
            }
        }

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

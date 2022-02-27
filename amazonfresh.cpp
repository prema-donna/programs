#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'foo' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING_ARRAY codeList
 *  2. STRING_ARRAY shoppingCart
 */

int foo(vector<string> codeList, vector<string> shoppingCart) {
    map<int,vector<string>> codeMap;
    if(codeList.size() == 0) return 1;
    for(int i= 0; i< codeList.size(); i++)
    {
        vector<string> fCodeList;
        string currString;
        for(int j= 0; j< codeList[i].length(); j++){
            if(codeList[i][j] == ' '){
                fCodeList.push_back(currString);
                currString.clear();
                cout<<" ";
            }
            else{
                currString += codeList[i][j];
                cout<<codeList[i][j];
            }
        }
        cout<<endl;
        fCodeList.push_back(currString);
        codeMap.insert(make_pair(i,fCodeList));
    }
    cout<<"Shopping List: "<<endl;
    for(int i= 0; i< shoppingCart.size(); i++){
        for(int j= 0; j< shoppingCart[i].length(); j++) cout<<shoppingCart[i][j];
        cout<<endl;
    }
    int clIndex = 0, scIndex = 0, mIndex = 0, prevScIndex = -1;
    while(scIndex != shoppingCart.size()){
        if(codeMap[mIndex][clIndex] == shoppingCart[scIndex] || codeMap[mIndex][clIndex] == "anything"){
            if(prevScIndex != -1 && prevScIndex+1 != scIndex) return 0;
            prevScIndex = scIndex;
            clIndex++;
        }
        if(clIndex == codeMap[mIndex].size()){
            mIndex++;
            clIndex = 0;
            prevScIndex = -1;
        }
        scIndex++;
    }
    if(mIndex == codeMap.size()) return 1;
    return 0;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string codeList_count_temp;
    getline(cin, codeList_count_temp);

    int codeList_count = stoi(ltrim(rtrim(codeList_count_temp)));

    vector<string> codeList(codeList_count);

    for (int i = 0; i < codeList_count; i++) {
        string codeList_item;
        getline(cin, codeList_item);

        codeList[i] = codeList_item;
    }

    string shoppingCart_count_temp;
    getline(cin, shoppingCart_count_temp);

    int shoppingCart_count = stoi(ltrim(rtrim(shoppingCart_count_temp)));

    vector<string> shoppingCart(shoppingCart_count);

    for (int i = 0; i < shoppingCart_count; i++) {
        string shoppingCart_item;
        getline(cin, shoppingCart_item);

        shoppingCart[i] = shoppingCart_item;
    }

    int result = foo(codeList, shoppingCart);

    fout << result << "\n";

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

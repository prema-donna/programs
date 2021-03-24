#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

string output(vector<vector<string>> hd){
    cout<<"Hand: ";
    for(int i= 0; i< 10; i++){
        cout<<hd[i]<<" ";
        if(i > 4){
            if(i == 5)
                cout<<"Deck: ";
            cout<<hd[i]<<" ";
        }
    }
    cout<<"Best hand: ";
    int r_flush_count = 0;
    int s_flush_count = 0;
    int four_count = 0;
    int flush_count = 0;
    int straight_count = 0;
    int tpair_count = 0;
    
    for(int i= 0; i< 9; i++){
        string s= hd[i];
        if(s[0] == 'T' || s[0] == 'J' || s[0] == 'Q' || s[0] == 'K' || s[0] == 'A') {
            r_flush_count++;
            s_flush_count++;
        }
        for(int j= i+1; j< 10; j++){
            if((hd[j][0] == 'T' || hd[j][0] == 'J' || hd[j][0] == 'Q' || hd[j][0] == 'K' || hd[j][0] == 'A') && hd[j][1] = s[1]){
                r_flush_count++;
                s_flush_count++;
            }
            if(hd[j][0] == s[0]){
                four_count++;
                
            }
        }
    }
    
    return "highest-card\n";
    
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    vector<vector<string>> hand_deck = {TH, JH, QC, QD, QS, QH, KH, AH, 2S, 6S,
                                        2H, 2S, 3H, 3S, 3C, 2D, 3D, 6C, 9C, TH,
                                        2H, 2S, 3H, 3S, 3C, 2D, 9C, 3D, 6C, TH,
                                        2H, AD, 5H, AC, 7H, AH, 6H, 9H, 4H, 3C,
                                        AC, 2D, 9C, 3S, KD, 5S, 4D, KS, AS, 4C,
                                        KS, AH, 2H, 3C, 4H, KC, 2C, TC, 2D, AS,
                                        AH, 2C, 9S, AD, 3C, QH, KS, JS, JD, KD,
                                        6C, 9C, 8C, 2D, 7C, 2H, TC, 4C, 9S, AH,
                                        3D, 5S, 2H, QD, TD, 6S, KH, 9H, AD, QH};
    output(hand_deck);
    return 0;
}
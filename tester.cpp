#include <bits/stdc++.h>
#include <vector>
using namespace std;
int main(){
    vector<string> str = {"dog","racecar","car"};
    string res="";
    sort(str.begin(),str.end());
    int x = min(str[0].size(),str[str.size()-1].size());
    for (int i = 0; i < x; i++){
        char temp = str[0][i];
        for(int j = 0; j < str.size(); j++){
            if(temp!=str[j][i]){
                // return res;
            }
        }
        res+=temp;
    }
    // return res;
    cout<< res;
}
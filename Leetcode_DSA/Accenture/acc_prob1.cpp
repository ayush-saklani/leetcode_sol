// PROBLEM STATEMENT: Given a string, find the character which has the maximum frequency. 
// If there are multiple characters with the same frequency, then print the character which appears first in the string.
#include<bits/stdc++.h>
using namespace std;
int main(){
    string str ;
    str = "apple";
    int n = str.length();
    unordered_map<char,int> mp;
    for(int i=0;i<n;i++){
        mp[str[i]]++;
    }
    int max_freq = 0;
    char max_char;
    for(int i=0;i<n;i++){
        if(mp[str[i]]>max_freq){
            max_freq = mp[str[i]];
            max_char = str[i];
        }
    }
    cout<<max_char;
    return 0;
}
// Test case: 
// apple => p
// applee => p

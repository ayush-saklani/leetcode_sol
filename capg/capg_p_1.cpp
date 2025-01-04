#include<bits/stdc++.h>
using namespace std;
int main(){
    string s = "Move#Hash#to#Front";
    string s1,res;
    for(int i=0;i<s.size();i++){
        if(s[i]=='#'){
            res.push_back(s[i]);
        }else{
            s1.push_back(s[i]);
        }
    }
    // string res = s2.append(s1);
    res = res + s1;
    cout<<res<<endl;
    return 0;
}
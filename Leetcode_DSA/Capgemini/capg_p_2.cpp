#include<bits/stdc++.h>
using namespace std;
int main(){
    string s = "aabbbbeeeeffggg";
    cout<<s<<endl;
    string res;
    for(int i=0;i<s.size();i++){
        int temp = 1;
        while(i<s.size()-1 && s[i]==s[i+1]){
            temp++;
            i++;
        }
        res = res + s[i];
        if(temp>0){
            res = res + to_string(temp);
        }
    }
    cout<<res<<endl;
    return 0;
}
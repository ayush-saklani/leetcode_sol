#include <bits/stdc++.h>
// #include <vector>
using namespace std;
int main(){
    string s="   -42";
    vector<char> str(s.begin(),s.end());
        int res=0;        
        int lock=0;
        for(int i = 0 ; i<str.size() ; i++){
            cout<<(str[i])<<endl;
            if(str[i]==' ') ;
            else if(str[i]=='-') lock++;
            else if(int(str[i]-'0')>=0 && int(str[i]-'0')<=9){
                res=(res*10)+int(str[i]-'0');
            }
        }
        if(lock!=0){
            cout<<(res*-1)<<endl;
        }
        else{
            cout<< res;
        }
        // return res;
}
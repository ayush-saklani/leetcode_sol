#include <bits/stdc++.h>
using namespace std;
int main(){
    int a = 35;
    for(int i = 1; i < ((a/2)+1); i++){
        if(a%i==0){
            cout<<i<<" ";
        }
    } 
    return 0;
}
//
#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr= {1, 2, 3, 3, 4, 1, 4, 5, 1, 2};
    for(int i = 0; i < arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    map<int , int> m;
    for(int i = 0; i < arr.size(); i++){
        m[arr[i]]++;
    }
    for(auto i :m){
        cout<< i.first <<" occurs "<< i.second <<" times"<<endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<vector<int>> arr = {{4, 2},{4, 0},{1, 2}};
    // int n = arr.size();
    // vector<int> res(n, 0);
    // for(int i = 0; i < n; i++){
    //     res[i] = res[i] + arr[i][0]*4 + arr[i][1]*2;
    // }
    // for(int i = 0; i < n; i++){
    //     cout<<res[i]<<" ";
    // }
    arr.erase(arr.begin());
    for(int i = 0; i < arr.size(); i++){
        cout<<arr[i][0]<<" "<<arr[i][1]<<endl;
    } 
    return 0;
}
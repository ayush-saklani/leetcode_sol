#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr;
    unordered_map<int, int> m;
    int n,temp;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> temp;
        arr.push_back(temp);
        m[temp]++;
    }
    for(auto i : m){
        cout << i.first << " " << i.second << endl;
    }
    return 0;
}
// Input: 10 1 2 3 4 5 1 2 3 4 5
// Output: 
// 1 2 
// 2 2 
// 3 2 
// 4 2 
// 5 2

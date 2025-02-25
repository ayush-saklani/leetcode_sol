#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<vector<int>> arr =  {{1, 2}, {2, 1}, {3, 4}, {4, 5}, {5, 4}}; 
    int n = arr.size();
    unordered_map<int, int> mp;
    for(int i = 0; i < n; i++){
        if(mp[arr[i][1]] && mp[arr[i][1]] == arr[i][0]){
            cout << arr[i][0] << " " << arr[i][1] << endl;
        }else{
            mp[arr[i][0]] = arr[i][1];
        }
    }
    return 0;
}
// Input: {{1, 2}, {2, 1}, {3, 4}, {4, 5}, {5, 4}}
// Output: {2 1} {5 4}
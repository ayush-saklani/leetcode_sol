#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr = {1, 2, 2, 3, 4, 4, 5, 6, 7, 8, 9, 10};
    int n = arr.size();
    unordered_map<int, bool> mp;
    for(int i = 0; i < n; i++){
        if(mp[arr[i]]){
            cout << arr[i] << " ";
        }
        mp[arr[i]] = true;
    }
    return 0;
}
// Input: 1 2 2 3 4 4 5 6 7 8 9 10
// Output: 2 4
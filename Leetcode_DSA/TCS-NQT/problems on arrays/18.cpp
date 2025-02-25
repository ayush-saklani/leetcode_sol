#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr = {20, 15, 26, 2, 98, 6};
    vector<int> arr1 = arr;
    sort(arr1.begin(), arr1.end());
    int n = arr.size();
    unordered_map<int, int> mp;
    for(int i = 0; i < n; i++){
        mp[arr1[i]] = i+1;
    }
    for(int i = 0; i < n; i++){
        arr[i] = mp[arr[i]];
    }
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
// Input: 1 2 2 3 4 4 5 6 7 8 9 10
// Output: 2 4
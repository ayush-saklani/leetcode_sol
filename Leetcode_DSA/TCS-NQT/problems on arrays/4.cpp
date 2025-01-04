#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr;
    int n,temp;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> temp;
        arr.push_back(temp);
    }
    reverse(arr.begin(), arr.end());    // Using reverse function
    for(int i=0;i<n/2;i++){             // Using swap function
        swap(arr[i],arr[n-i-1]);
    }
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
// Input: 5 1 2 3 4 5
// Output: 5 4 3 2 1

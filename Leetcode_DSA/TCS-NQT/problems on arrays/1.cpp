#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr;
    int n,temp,min = INT_MAX;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> temp;
        arr.push_back(temp);
    }
    for (int i = 0; i < n; i++)    {
        arr[i] < min ? min = arr[i] : min;
    }
    cout << min;
    return 0;
}
// Input: 5 3 2 1 4 5
// Output: 1

#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr;
    int n,temp,max = INT_MIN;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> temp;
        arr.push_back(temp);
    }
    for (int i = 0; i < n; i++)    {
        max = (arr[i] > max) ? arr[i] : max;
    }
    cout << max;
    return 0;
}
// Input: 5 3 2 1 4 5
// Output: 5

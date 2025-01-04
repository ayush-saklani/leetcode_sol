#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr;
    int n,temp,min = INT_MAX,max = INT_MIN,minsecond = INT_MIN,maxsecond = INT_MAX;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> temp;
        arr.push_back(temp);
    }
    for (int i = 0; i < n; i++)    {
        if( arr[i] < min ) {
            minsecond  = min;
            min = arr[i];
        }if( arr[i] > max ) {
            maxsecond  = max;
            max = arr[i];
        }
    }
    cout << minsecond << " " << maxsecond;
    return 0;
}
// Input: 10 3 2 1 4 5 6 7 8 9 10
// Output: 2 9

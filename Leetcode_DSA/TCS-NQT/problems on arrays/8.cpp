#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    int k = 3;
    int n = arr.size();
    reverse(arr.begin()+k, arr.end());
    reverse(arr.begin(), arr.end()-n+k);
    reverse(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
// output: 4 5 6 7 8 9 10 1 2 3
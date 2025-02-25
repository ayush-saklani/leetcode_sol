#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr = {1, 2, 2, 3, 4, 4, 5, 6, 7, 8, 9, 10};
    sort(arr.begin(), arr.end());
    int n = arr.size();
    float median = 0;
    if (n % 2 == 0){
        median = (arr[n / 2] + arr[n / 2 - 1]) / 2.0;
    }
    else{
        median = arr[n / 2];
    }
    cout << median<<endl;
    return 0;
}
// Output: 4
// Input: 5 3 2 1 4 5 6

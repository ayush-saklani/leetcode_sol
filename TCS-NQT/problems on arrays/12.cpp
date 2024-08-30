#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr={1,2,2,3,4,4,5,6,7,8,9,10};
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int first = 1;
    for (int i = 2; i < n; i++){
        if(arr[i]!=arr[first]){
            first++;
            arr[first] = arr[i];
        }
    }
    for(int i=0;i<first;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
// Input: 5 3 2 1 4 5
// Output: 15

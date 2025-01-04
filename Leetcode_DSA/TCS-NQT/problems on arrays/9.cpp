#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr;
    int n,temp;
	int sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> temp;
        arr.push_back(temp);
		sum += temp;
    }
    cout << sum/n;
    return 0;
}
// Input: 5 3 2 1 4 5
// Output: 15

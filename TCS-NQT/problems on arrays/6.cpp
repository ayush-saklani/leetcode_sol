#include<bits/stdc++.h>
using namespace std;
int main(){
	vector<int>arr = {1,2,3,4,5,6,7,8,9,10};
	int n = arr.size();
	sort(arr.begin(), arr.end());
    reverse((arr.begin()+(n/2)), arr.end());
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}
// Output: 1 2 3 4 5 10 9 8 7 6
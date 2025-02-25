#include <bits/stdc++.h>
using namespace std;
void insertatend(vector<int> &arr, int data){
    arr.push_back(data);
}
void insertatbeginning(vector<int> &arr, int data){
    arr.insert(arr.begin(), data);
}
void insertatindex(vector<int> &arr, int data, int index){
    arr.insert(arr.begin()+index, data);
}
int main(){
    vector<int> arr={1,2,2,3,4,4,5,6,7,8,9,10};
    int n = arr.size();
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    insertatend(arr, 100000000);
    insertatbeginning(arr, 100000000);
    insertatindex(arr, 100000000, 2);
    n = arr.size();
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
// Input: 1 2 2 3 4 4 5 6 7 8 9 10 
// Output: 100000000 1 100000000 2 2 3 4 4 5 6 7 8 9 10 10000000
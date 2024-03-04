#include<bits/stdc++.h> //pending
using namespace std;
int main(){
    int n;
    cin>>n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++){
        cin>>arr[i];
    }
    cout<<"press 1 for ..."<<endl;
    cout<<"press 2 for ..."<<endl;
    while (1){
        int choice;
        cin>>choice;
        switch (choice){
        case 1:
            break;
        case 2:
            break;        
        default:
            cout<<"invalid choice"<<endl;
            cout<<"Exiting....."<<endl;
            return 0;
            break;
        }
    }
    return 0;
}
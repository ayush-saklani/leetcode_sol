// PROBLEM STATEMENT : Given a list of houses and a list of tasks, find the minimum number of tasks to be done to complete all the tasks.
// The tasks are to be done in the order they are given in the list.
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> a = { 2, 3, 3};
    int n = 4;
    int m = a.size();
    queue<int> q;
    for(int i=0;i<m;i++){
        q.push(a[i]);
    }
    int res = -1 ;  // it will be 0 in the first iteration
    int it = 1;     // iterator to iterate over the queue from 1 to n
    while (!q.empty()){
        if(it==q.front()){
            q.pop();
            while(!q.empty() && q.front()==it){
                q.pop();
            }
            res++;
            cout << "it: " << it << " res: " << res << endl;
        }else{
            res++;
            cout << "it: " << it << " res: " << res << endl;
        }
        it++;
        if(it>n){
            it=1;
        }
    }
    cout<<res;
    return 0;
}
// Test case: 
// 4 3 3 2 3
// 1 2 3 4  => houses
// 3 task => at 3rd house then 2nd house then 3rd house 
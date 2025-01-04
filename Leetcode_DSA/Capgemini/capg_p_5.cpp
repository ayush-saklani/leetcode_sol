#include <bits/stdc++.h>
using namespace std;
int functionality(int a ,int b){
    int res = pow(a,3) + (pow(a,2)*b) + (2*pow(a,2)*b) + (2*a*pow(b,2)) + (a*pow(b,2)) + pow(b,3);
    return res;    
}
int main(){
    int a = 2, b = 3;
    cout<<functionality(a,b)<<endl;
    return 0;
}
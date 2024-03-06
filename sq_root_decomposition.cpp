#include<bits/stdc++.h>
using namespace std;
int* decompose(int*arr,int n){
    int block_size = ceil(sqrt(n));
    int* res = new int[block_size];
    for (int i = 0; i < block_size; i++){
        res[i]=0;
    }
    for (int i = 0; i < n; i++){
        res[i/block_size]+=arr[i];
    }
    return res;
}
int sum_query(int* arr,int* block,int n,int ql,int qr){
    int block_size = ceil(sqrt(n));
    int block_start=ql/block_size,block_end=qr/block_size;
    int res=0,i;
    i = block_start+1;
    while (i<block_end){
        res=res+block[i];
        i++;
    }
    i = ql;
    while((i/block_size)==block_start){
        res = res + arr[i];
        i++;
    }
    i = qr;
    while((i/block_size)==block_end){
        res = res + arr[i];
        i--;
    }
    return  res;
}
void update_query(int* arr,int* block,int n,int index,int val){
    int val_p_diff = val-arr[index];
    int block_size = ceil(sqrt(n));
    arr[index] = val;
    block[index/block_size] += val_p_diff;
    return ;
}
void print_array_and_block(int* arr,int* block,int n){
    for(int i = 0; i < n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for(int i = 0; i < ceil(sqrt(n));i++){
        cout<<block[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int n;
    cin>>n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++){
        cin>>arr[i];
    }
    int *block = decompose(arr,n);
    print_array_and_block(arr,block,n);
    
    cout<<"press 1 for range sum"<<endl;
    cout<<"press 2 for update at index"<<endl;
    while (1){
        int choice;
        cin>>choice;
        switch (choice){
        case 1:
            int start,end;
            cout<<"start -> end ";
            cin>>start>>end;
            cout<<sum_query(arr,block,n,start,end);
            break;
        case 2:
            int index,value;
            cout<<"index -> value ";
            cin>>index>>value;
            update_query(arr,block,n,index,value);
            cout<<"updation complete "<<endl;
            print_array_and_block(arr,block,n);
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
//  9 1 2 3 4 5 6 7 8 9


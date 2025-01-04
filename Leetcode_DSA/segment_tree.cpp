#include<bits/stdc++.h>
using namespace std;
void build_segment_tree(int*arr,int* seg_tree,int l,int r,int tree_index,int n){
    if(l==r){
        seg_tree[tree_index] = 0;
        if(l<n)
            seg_tree[tree_index] = arr[l];
        return ;
    }
    else{
        int mid = (l+r)/2;
        build_segment_tree(arr,seg_tree,l,mid,(tree_index*2+1),n);
        build_segment_tree(arr,seg_tree,mid+1,r,(tree_index*2+2),n);
    }
    seg_tree[tree_index] = seg_tree[tree_index*2+1] + seg_tree[tree_index*2+2];
}
int sum_query(int* seg_tree,int l,int r,int ql,int qr,int tree_index){
    int mid= (l+r)/2;
    // cout<<endl<<l<<" "<<mid<<" "<<r;
    if(qr<l || ql>r) return 0;
    if(ql<=l && qr>=r){
        return  seg_tree[tree_index];
    }
    int temp_l = sum_query(seg_tree,l,mid,ql,qr,2*tree_index+1);
    int temp_r = sum_query(seg_tree,mid+1,r,ql,qr,2*tree_index+2);
    return  temp_l+temp_r;
}
void update_query(int* seg_tree,int l,int r,int upd_index,int tree_index,int val_p_diff){
    if(upd_index<l || upd_index>r) return ;
    if(upd_index>=l && upd_index<=r)
        seg_tree[tree_index]+=val_p_diff;
    if(l==r)
        return;
    int mid= (l+r)/2;
    update_query(seg_tree,l,mid,upd_index,2*tree_index+1,val_p_diff);
    update_query(seg_tree,mid+1,r,upd_index,2*tree_index+2,val_p_diff);
    return ;
}
void print_seg_tree(int* seg_tree,int seg_tree_size){
    for(int i = 0; i < seg_tree_size;i++){
        cout<<seg_tree[i]<<" ";
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
    int seg_tree_size=2*pow(2, ceil(log2(n)))-1;
    int* seg_tree = new int[seg_tree_size];
    build_segment_tree(arr,seg_tree,0,pow(2, ceil(log2(n)))-1,0,n); //pow(2, ceil(log2(n))) means last layer ko fully full karne ke baad kitne element ayenge
    print_seg_tree(seg_tree,seg_tree_size);
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
            cout<<sum_query(seg_tree,0,pow(2, ceil(log2(n)))-1,start,end,0);
            break;
        case 2:
            int index,value;
            cout<<"index -> value ";
            cin>>index>>value;
            update_query(seg_tree,0,pow(2, ceil(log2(n)))-1,index,0,value-arr[index]);
            cout<<"updation complete "<<endl;
            print_seg_tree(seg_tree,seg_tree_size);
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
//  5 1 2 3 4 5 2 0 3

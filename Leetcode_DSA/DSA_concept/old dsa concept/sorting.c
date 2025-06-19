#include<stdio.h>
#include<stdlib.h>
void display(int arr[],int n){
    printf("Array is -> ");
    for (int i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }
}
void bubble_sort(int arr[],int n){
    int temp;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n-i-1; j++){
            if(arr[j]>arr[j+1]){
            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
            }
        }
    }
}
void mergesort(int arr[],int low,int high){
    int mid;
    if (low<high){
        mid=(low+high)/2;
        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }    
}
void merge(int arr[] ,int low ,int mid ,int high){
    int temp[100],j=low,m=high+1,i;
    for (int i = low; i <= mid && m<=high ; i++){
        if(arr[j]<=arr[m]){
            temp[i]=arr[j];j++;
        }
        else{
            temp[i]=arr[m]; m++;
        }
    }
    if(j>mid){
        for(int k=m;k<mid;k++){
            temp[i]=arr[k]; i++;
        }
    }
    for(int k=low;k<=high;k++){
        arr[k]=temp[k];
    }
    
}
int main(){
    int arr[100],n;
    printf("Enter size of array\n");
    scanf("%d",&n);
    printf("Enter array \n");
    for (int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }
    display(arr,n);
    bubble_sort(arr,n);
    display(arr,n);
    return 0;
}
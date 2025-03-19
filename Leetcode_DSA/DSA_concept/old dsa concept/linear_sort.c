#include <stdio.h>
int search(int arr[], int N, int x){
	for (int i = 0; i < N; i++)
		if (arr[i] == x)
			return i+1;
	return -1;
}
void display(int arr[], int size){
    printf("Array is ->");
	for (int i = 0; i < size; i++){
		printf("%d ", arr[i]);
    }
	printf("\n");
}
int main(void){
    int arr[100],n,x;
	printf("Enter array size -> ");
    scanf("%d",&n);
    printf("Enter array -> ");
    for(int i = 0 ; i<n ; i++){
        scanf("%d",&arr[i]);
    }
	printf("Entered array -> ");
	display(arr, n);    
    printf("Enter item to search -> ");
    scanf("%d",&x);
	int result = search(arr, n, x);
	(result == -1)
		? printf("Element is not present in array")
		: printf("Element is present at index %d", result);
	return 0;
}

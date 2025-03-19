#include <stdio.h>
void bubbleSort(int arr[], int n){
	for (int i = 0; i < n - 1; i++){
    	for (int j = 0; j < n - i - 1; j++){
			if (arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
void display(int arr[], int size){
    printf("Array is ->");
	for (int i = 0; i < size; i++){
		printf("%d ", arr[i]);
    }
	printf("\n");
}
int main()
{
	int arr[100],n;
	printf("Enter array size \n");
    scanf("%d",&n);
    printf("Enter array -> ");
    for(int i = 0 ; i<n ; i++){
        scanf("%d",&arr[i]);
    }
	printf("Entered array -> ");
	display(arr, n);
	bubbleSort(arr, n);
	printf("Sorted array -> ");
	display(arr, n);
	return 0;
}

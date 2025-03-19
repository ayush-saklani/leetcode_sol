#include <stdio.h>
void display(int arr[], int size){
    for (int i = 0; i < size; i++){
		printf("%d ", arr[i]);
    }
	printf("\n");
}
void insertionSort(int array[], int size) {
    for (int step = 1; step < size; step++) {
        int key = array[step];
        int j = step - 1;
        // Compare key with each element on the left of it until an element smaller than
        // it is found.
        // For descending order, change key<array[j] to key>array[j].
        while (key < array[j] && j >= 0) {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
    }
}
int main(){
    int arr[100],n;
	printf("Enter array size -> ");
    scanf("%d",&n);
    printf("Enter array -> ");
    for(int i = 0 ; i<n ; i++){
        scanf("%d",&arr[i]);
    }
	printf("Entered array -> ");
	display(arr, n);    
    insertionSort(arr,n);
    printf("Sorted array  -> ");
    display(arr,n);
}
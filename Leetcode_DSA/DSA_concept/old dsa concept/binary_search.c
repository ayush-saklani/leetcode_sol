#include <stdio.h>
int binarySearch(int arr[], int l, int r, int x){
	if (r >= l) {
		int mid = l + (r - l) / 2;

		// If the element is present at the middle
		// itself
		if (arr[mid] == x)
			return mid+1;

		// If element is smaller than mid, then
		// it can only be present in left subarray
		if (arr[mid] > x)
			return binarySearch(arr, l, mid - 1, x);

		// Else the element can only be present
		// in right subarray
		return binarySearch(arr, mid + 1, r, x);
	}

	// We reach here when element is not
	// present in array
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
	int result = binarySearch(arr, 0, n - 1, x);
	(result == -1)
		? printf("Element is not present in array")
		: printf("Element is present at index %d", result);
	return 0;
}

// Question Link: https://www.pepcoding.com/resources/online-java-foundation/time-and-space-complexity/quick-select-official/ojquestion
// Video Link: https://youtu.be/fnbImb8lo88?list=PL-Jc9J83PIiFc7hJ5eeCb579PS8p-en4f
#include <stdio.h>
int partition(int arr[], const int low, const int high, const int pivot){
    int j = low;
    for (int i = low; i <= high; i++)
        if (arr[i] <= pivot)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            ++j;
        }
    
    return j - 1;
}

int quickselect(int arr[], int low, int high, const int k){
    int pivot = arr[high];
    int pivotIndex = partition(arr, low, high, pivot);

    if(k > pivot)
        return quickselect(arr, pivotIndex + 1, high, k);
    else if(k < pivot)
        return quickselect(arr, low, pivotIndex - 1, k);
    else
        return arr[pivotIndex];
}


void printArray(const int *nums, const int *n){
	for(int i = 0; i < *n; ++i)
		printf("%d%s", nums[i], i != *n - 1  ? ", " : "\n");
}

int main(void) {
    printf("Enter size of array: ");
    int n; scanf("%d", &n);

    printf("Enter elements in array: ");
    int arr[n];
    for(int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);

    printf("Enter pivot: ");
    int pivot; scanf("%d", &pivot);
    
    printf("Array before partition: ");
	printArray(arr,&n);
    partition(arr, 0, n - 1, pivot);
    printf("\nArray after partition: ");
	printArray(arr,&n);
	printf("\n");
}

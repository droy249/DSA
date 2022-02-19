// Question Link: https://www.pepcoding.com/resources/online-java-foundation/time-and-space-complexity/partition-an-array-official/ojquestion
// Question Video: https://youtu.be/if40LxQ8_Xo?list=PL-Jc9J83PIiFc7hJ5eeCb579PS8p-en4f
#include <stdio.h>

void partition(int nums[], const int n, const int pivot)
{
    /* 0 to j-1 >===> < pivot
	j - 1 >====> = pivot
	j to i-1 >===> > pivot
	i to n >===> unkwown */

    for(int j = 0, i = 0; i < n; ++i)
    {
        if(nums[i] <= pivot)
        {
            int tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
            ++j;
        }
    }
}

void printArray(const int *nums, const int *n){
	for(int i = 0; i < *n; ++i)
		printf("%d%s", nums[i], i != *n - 1  ? ", " : "\n");
}

int main(int argc, char const *argv[])
{
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
    partition(arr, n, pivot);
    printf("\nArray after partition: ");
	printArray(arr,&n);
	printf("\n");
}

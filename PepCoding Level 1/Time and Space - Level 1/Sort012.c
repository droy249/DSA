// Question Link: https://www.pepcoding.com/resources/online-java-foundation/time-and-space-complexity/sort-012-official/ojquestion
// Video Link: https://youtu.be/MbV26HWqxrs?list=PL-Jc9J83PIiFc7hJ5eeCb579PS8p-en4f
// Leetcode Link: https://leetcode.com/problems/sort-colors/
#include <stdio.h>
#include <stdlib.h>

void sort012CountSort(int arr[], const int n)
{
    int count[] = {0,0,0};
    for (int i = 0; i < n; i++)
        ++count[arr[i]];
    
    count[1] += count[0];
    count[2] += count[1];

    int *temp = calloc(n, sizeof(int));;
    for(int i = n - 1; ~i; --i)
        temp[--count[arr[i]]] = arr[i];
    
    for(int i = 0; i < n; ++i)
        arr[i] = temp[i];

    free(temp);
}

void sort012Partition(int arr[], int n)
{
/*  0 to j-1 >===> 0
	j to i-1 >===> 1
	i to k >===> unkwown 
    k+1 to end >===> 2 */
    
    int i = 0, j = 0, k = n - 1;
    while(i <= k) {
        if(arr[i] == 0){
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            ++i;
            ++j;
        }
        else if(arr[i] == 1){
            ++i;
        }
        else {
            int tmp  = arr[i];
            arr[i] = arr[k];
            arr[k] = tmp;
            --k;
        }
    }
	// return j - 1;
}

void printArray(const int *nums, const int n){
	for(int i = 0; i < n; ++i)
		printf("%d%s", nums[i], i != n - 1  ? ", " : "\n");
}

int main(int argc, char const *argv[])
{
    printf("Enter size of array: ");
    int n ;
    scanf("%d", &n);

    printf("Enter elemennts of array: ");
    int *arr = calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    printf("\n\nArray before sorting: ");
    printArray(arr, n);
    sort012CountSort(arr, n);
    // sort012Partition(arr, n);
    printf("\n\nArray after sorting: ");
    printArray(arr, n);
    free(arr);
}

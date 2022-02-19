// Question Link: https://www.pepcoding.com/resources/online-java-foundation/time-and-space-complexity/sort-01-official/ojquestion
// Video Link: https://youtu.be/jFrUwjx4eoA?list=PL-Jc9J83PIiFc7hJ5eeCb579PS8p-en4f
// Gfg Link: https://www.geeksforgeeks.org/segregate-0s-and-1s-in-an-array-by-traversing-array-once/#:~:text=1%2C%201%2C%201%5D-,Recommended,-%3A%20Please%20solve%20it
#include <stdio.h>

void sort01CountSort(int arr[], const int n)
{
    int count[] = {0,0};
    for (int i = 0; i < n; i++)
        ++count[arr[i]];
    
    count[1] += count[0];

    int temp[n];
    for(int i = n - 1; ~i; --i)
        temp[--count[arr[i]]] = arr[i];
    
    for(int i = 0; i < n; ++i)
        arr[i] = temp[i];
}

void sort01Partition(int arr[], int n)
{
    // int pivot = 1;
    int i = 0, j = 0;
    while(i < n) //nums[i] == 1 ? swap(&nums[i++], &nums[j++]) : ++i;
    {
        if(!arr[i])
        {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            ++i;
            ++j;
        }
        else 
            ++i;
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
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    printf("\n\nArray before sorting: ");
    printArray(arr, n);
    // sort01CountSort(arr, n);
    sort01Partition(arr, n);
    printf("\n\nArray after sorting: ");
    printArray(arr, n);
}

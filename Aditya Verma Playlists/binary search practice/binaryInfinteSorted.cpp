/* Given an infinite sorted array consisting 0s and 1s. The problem 
 * is to find the index of first ‘1’ in that array. As the array is
 * infinite, therefore it is guaranteed that number ‘1’ will be present 
 * in the array.
*/

#include <cstdio>
#include <cstdlib>
#include <ctime>

int searchFirstOne(bool *arr){
	int low = 0, high = 1;
	while(!arr[high])
		low = high, high <<= 1;
	
	int mid = -1;
	while (low <= high){
		mid = low + (high - low) / 2;
		if(arr[mid] and (!mid or !arr[mid-1])) return mid;
		else if(arr[mid]) high = mid - 1;
		else low = mid + 1;
	}
	return -1;
}

// Driver code
int main(){
	bool arr[100001] = {0};
	// float ones = 100000.0f * ((float)rand() / 32767.0f);
	srand(time(0));
	short one = rand();
	for(int i = one; i < 1e5; ++i) arr[i] = 1;
	printf("Index of first 1: %d\n", searchFirstOne(arr));
}

/* Given an array and a number k where k is smaller than size of array, we need to find the k’th smallest element in the given array. It is given that all array elements are distinct.

Example:
Input: arr[] = {7, 10, 4, 3, 20, 15}
k = 3
Output: 7
 */
#include <iostream>
#include <queue>										// for priority_queue class

// Time Complexity: O(n log k)
// Space Complexity: O(k)
int kthSmallestElement(const int *nums, const int &n, const int &k) {
	std::priority_queue<int> maxHeap;					// In C++, priority_queue is Min Heap by default
	for(int i{}; i < n; ++i){
		maxHeap.emplace(nums[i]);
		if(maxHeap.size() > k)
			maxHeap.pop();
	}
	return maxHeap.top();
}

int main(){
	int arr[] = {7,10,4,3,20,15}, n = sizeof(arr)/sizeof(*arr), k = 3;
	std::cout << "Kth smallest element of given array is " << kthSmallestElement(arr,n,k) << std::endl;
}
/* Given an array of integers and two numbers k1 and k2. Find the sum of all elements between given two k1’th and k2’th smallest elements of the array. It may  be assumed that all elements of array are distinct.

Example :
Input : arr[] = {20, 8, 22, 4, 12, 10, 14},  k1 = 3,  k2 = 6  
Output : 26          
         3rd smallest element is 10. 6th smallest element 
         is 20. Sum of all element between k1 & k2 is
         12 + 14 = 26 
*/
#include <iostream>
#include <queue>										

int kthSmallestElement(const int *nums, const int &n, const int &k) {
	std::priority_queue<int> maxHeap;
	for(int i{}; i < n;){
		maxHeap.emplace(nums[i++]);
		if(maxHeap.size() > k)
			maxHeap.pop();
	}
	return maxHeap.top();
}

int sumBetweenK1K2(const int *nums, const int &n, const int &k1, const int &k2) {
	const int k1thElement{kthSmallestElement(nums,n,k1)}, k2thElement{kthSmallestElement(nums,n,k2)};
	int sum{};
	for(int i{}; i < n; ++i)
		if(k1thElement < nums[i] and nums[i] < k2thElement)
			sum += nums[i];
	return sum;
}

int main(){
	const int nums[]{1,3,12,5,15,11}, n{sizeof(nums)/sizeof(*nums)}, k1{3}, k2{6};
	std::cout << "Sum of elements between k1 smallest and k2 smallest elements is " << sumBetweenK1K2(nums,n,k1,k2) << std::endl;
}
/* Given an array of n elements, where each element is at most k away from its target position, devise an algorithm that sorts in O(n log k) time. For example, let us consider k is 2, an element at index 7 in the sorted array, can be at indexes 5, 6, 7, 8, 9 in the given array.

Example:
Input : arr[] = {6, 5, 3, 2, 8, 10, 9}
k = 3 
Output : arr[] = {2, 3, 5, 6, 8, 9, 10}

Input : arr[] = {10, 9, 8, 7, 4, 70, 60, 50}
k = 4
Output : arr[] = {4, 7, 8, 9, 10, 50, 60, 70}

 */
#include <iostream>
#include <vector>
#include <queue>

// Time Complexity: O(n log k)
// Space Complexity: O(k)
std::vector<int> sortNearlySortedArray(std::vector<int> &nums, const int &k){
	
	std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
	int i{};
	for(const auto &num : nums){
		minHeap.emplace(num);
		if(minHeap.size() > k){
			nums.at(i++) = minHeap.top();
			minHeap.pop();
		}
	}
	
	while(!minHeap.empty()){
		nums.at(i++) = minHeap.top();
		minHeap.pop();
	}
	return nums;
}

int main(){
	const int k = 4;
	std::vector<int> nums{10, 9, 8, 7, 4, 70, 60, 50};
	std::vector<int> ans{sortNearlySortedArray(nums,k)};
	std::cout << "Array after sorting: ";
	for(const auto &num : ans)
		std::cout << num << " ";
	std::cout << std::endl;
}
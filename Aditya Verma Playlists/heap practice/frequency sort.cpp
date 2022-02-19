/* Print the elements of an array in the increasing frequency if 2 numbers have same frequency then print the one which came first.

Example:
Input : arr[] = {2, 5, 2, 8, 5, 6, 8, 8}
Output : arr[] = {8, 8, 8, 2, 2, 5, 5, 6} 
*/
#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <unordered_map>

void frequencySort(std::vector<int>& nums) {
	std::unordered_map<int,int> mp;
	for(const int &num:nums) ++mp[num];
	
	std::priority_queue<std::pair<int,int>> maxHeap;
	for(const std::pair<int,int> &p:mp){
		maxHeap.emplace(p.second, p.first);
	}
	
	int j{};
	while(!maxHeap.empty()){
		for(int i{}; i < maxHeap.top().first; ++i)
			nums.at(j++) = maxHeap.top().second;
		// std::cerr << maxHeap.top().first << ' ' << maxHeap.top().second << '\n';
		maxHeap.pop();
	}
}

int main(){
	std::vector<int> nums{2, 5, 2, 8, 5, 6, 8, 8};
	frequencySort(nums);
	std::cout << "Sorted array is given by: ";
	for(const int &num:nums)
		std::cout << num << ' ';
	std::cout << std::endl;
}
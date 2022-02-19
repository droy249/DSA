/* Given an unsorted array and two numbers x and k, find k closest values to x.

Input : arr[] = {10, 2, 14, 4, 7, 6}, x = 5, k = 3 
Output : 4 6 7

Input : arr[] = {-10, -50, 20, 17, 80}, x = 20, k = 2
Output : 17, 20
 */
#include <iostream>
#include <vector>
#include <queue>
#include <utility>

std::vector<int> kClosestNumbers(std::vector<int> &nums, const int &k, const int &x) {
	std::priority_queue<std::pair<int,int>> maxHeap;
	for(const int &num:nums){
		maxHeap.emplace(abs(x - num), num);
		if(maxHeap.size() > k)
			maxHeap.pop();
	}
	
	std::vector<int> ans;
	while(!maxHeap.empty()){
		ans.emplace_back(maxHeap.top().second);
		maxHeap.pop();
	}
	
	return ans;
}

int main() {
	std::vector<int> nums{10, 2, 14, 4, 7, 6};
	const int x = 5, k = 3 ;
	
	std::vector<int> ans{kClosestNumbers(nums,k,x)};
	
	std::cout << "The " << k << " closest elements to " << x << " are: ";
	for(const int &num:ans){
		std::cout << num << ' ';
	}
	std::cout << std::endl;
}
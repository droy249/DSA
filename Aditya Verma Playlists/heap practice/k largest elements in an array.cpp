/* Write an efficient program for printing k largest elements in an array. Elements in array can be in any order.

For example, if given array is [1, 23, 12, 9, 30, 2, 50] and you are asked for the largest 3 elements i.e., k = 3 then your program should print 50, 30 and 23.
 */
#include <iostream>
#include <vector>
#include <queue>
#include <functional>

std::vector<int> kLargestElements(std::vector<int> &nums, const int &k){
	std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
	for(const auto &num : nums){
		minHeap.emplace(num);
		if(minHeap.size() > k)
			minHeap.pop();
	}
	std::vector<int> ans(k);
	while(k){
		ans.emplace_back(minHeap.top());
		minHeap.pop();
	}
	return ans;
}

int main(){
	const int k = 3;
	std::vector<int> nums{7,10,4,3,20,15};
	std::vector<int> ans{kLargestElements(nums,k)};
	std::cout << "K largest element of given array are: ";
	for(const auto &num : ans)
		std::cout << num << " ";
	std::cout << std::endl;
}
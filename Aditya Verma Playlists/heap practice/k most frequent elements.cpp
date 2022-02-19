/* Given an array of n numbers. Your task is to read numbers from the array and keep at-most K numbers at the top (According to their decreasing frequency) every time a new number is read. We basically need to print top k numbers sorted by frequency when input stream has included k distinct elements, else need to print all distinct elements sorted by frequency.

Example:
Input :  arr[] = {1,1,1,2,2,3}
k = 2
Output : {1,2}
*/
#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <unordered_map>

std::vector<int> topKFrequent(std::vector<int> &nums, const int &k) {
	std::unordered_map<int,int> mp;
	for(const int &num:nums) ++mp[num];
	
	std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<std::pair<int,int>>> minHeap;
	for(const std::pair<int,int> &p:mp){
		minHeap.emplace(p.second, p.first);
		if(minHeap.size() > k)
			minHeap.pop();
	}
	
	std::vector<int> ans;
	while(!minHeap.empty()){
		ans.emplace_back(minHeap.top().second);
		std::cerr << minHeap.top().first << ' ' << minHeap.top().second << '\n';
		minHeap.pop();
	}
	
	return ans;
}

int main(){
	std::vector<int> nums{1,1,1,2,2,3};
	const int k = 2;
	std::vector<int> ans{topKFrequent(nums,k)};
	std::cout << "The k most frequent elements are: ";
	for(const int &num:ans)
		std::cout << num << ' ';
	std::cout << std::endl;
}
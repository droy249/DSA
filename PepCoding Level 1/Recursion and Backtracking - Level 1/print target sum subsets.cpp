// Question Link: https://www.pepcoding.com/resources/online-java-foundation/recursion-backtracking/target-sum-subsets-official/ojquestion
// Video Link: https://youtu.be/HGDmj5NrrjM?list=PL-Jc9J83PIiFxaBahjslhBD1LiJAV7nKs
// LeetCode link: https://leetcode.com/problems/combination-sum/
#include <iostream>
#include <vector>
using namespace std;

// Approach 1: My solution
void printTargetSumSubsets(vector<int>const& elements, const int& target, int index = 0, int sumSoFar = 0, vector<int> subset = {}){
	if(sumSoFar > target or (index == elements.size() and sumSoFar < target)) return;
	else if(sumSoFar == target){
		for(const int& element : subset)
			cout << element << ' ';
		cout << endl;
		return;
	}
	
	// // The part which PepCoding did different (but is also quite smart)
	// if(index == elements.size()){
		// if(target == sumSoFar){
			// for(const int& element : subset)
				// cout << element << ' ';
			// cout << endl;
		// }
		// return;
	// }
	
	printTargetSumSubsets(elements, target, index + 1, sumSoFar, subset);
	subset.emplace_back(elements.at(index));
	printTargetSumSubsets(elements, target, index + 1, sumSoFar + elements.at(index), subset);
}

int main(){
	cout << "Enter number of elements: ";
	int n; cin >> n;
	
	cout << "Enter the elements to choose from:" << endl;
	vector<int> elements;
	int element;
	while(n-- and cin >> element)
		elements.emplace_back(element);
	
	cout << endl << "Enter target to achieve: ";
	int target; cin >> target;
	
	cout << endl << "Subsets that add up to given target are: " << endl;
	printTargetSumSubsets(elements, target);
}
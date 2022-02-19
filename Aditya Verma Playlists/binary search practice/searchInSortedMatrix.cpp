/* SEARCH IN A ROW WISE AND COLUMN WISE SORTED MATRIX:

Given an n x n matrix and a number x, find the position of x in the matrix if it is present in it. Otherwise, print “Not Found”. In the given matrix, every row and column is sorted in increasing order. The designed algorithm should have linear time complexity.

Expected Time Complexity = O(n + m) instead of O(n * m)
where n = number of rows
	  m = number of columns
	  
Question link: https://www.geeksforgeeks.org/search-in-row-wise-and-column-wise-sorted-matrix/

Divide and Conquer Approach: https://www.geeksforgeeks.org/search-in-a-row-wise-and-column-wise-sorted-2d-array-using-divide-and-conquer-algorithm/
(Time Complexity: O(n ^ 1.58)

Another Approach: https://www.geeksforgeeks.org/search-element-sorted-matrix/
Time Complexity: O(log n + log m)
 */

#include <iostream>
#include <vector>
using namespace std;

vector<int> searchSortedMatrix(vector<vector<int>> &matrix, const int &key) {
	if(!matrix.size() or key < matrix.front().front() or key > matrix.back().back()) return {-1,-1};
	
	int row = 0, column = matrix.back().size() - 1;
	while(row < matrix.size() and column >= 0) {
		const int cell = matrix.at(row).at(column);
		if(cell == key) return {row, column};
		cell > key ? --column : ++row;
	}
	return {-1,-1};
}

int main() {
	vector<vector<int>> matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
	while(true){
		int key; cin >> key;
		if(key < 0) break;
		
		vector<int> ans = searchSortedMatrix(matrix,key);
		if(ans == vector<int> {-1,-1}) cout << "Element not found" << endl;
		else cout << "Element found at position: (" << ans.front() << "," << ans.back() << ")" << endl;
	}
	cout << "Exiting..." << endl;
}

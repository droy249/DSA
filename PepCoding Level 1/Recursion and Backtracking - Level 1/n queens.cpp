// Question Link: https://www.pepcoding.com/resources/online-java-foundation/recursion-backtracking/n-queens-official/ojquestion
// Video Link: https://youtu.be/05y82cP3bJo?list=PL-Jc9J83PIiFxaBahjslhBD1LiJAV7nKs

// Time Complexity: O(n!)
// Space Complexity: O(n * n)
// Analysis Link: https://leetcode.com/problems/n-queens/discuss/1223006/N-Queens-or-Easy-Backtracking-Solution-w-Explanation

#include <iostream>
#include <vector>
using namespace std;

// While checking for valid position, we only need to check the positions ABOVE the given cell of the given row
bool isValidPositon(vector<vector<bool>>& chessBoard, const int& row, const int& col){
	// Check column above cell
	for(int i{row - 1}, j{col}; i >= 0; --i)
		if(chessBoard.at(i).at(j))
			return false;
	
	// Check left diagonal pointing outwards from cell
	for(int i{row - 1}, j{col - 1}; i >= 0 and j >= 0; --i, --j)
		if(chessBoard.at(i).at(j))
			return false;
	
	// Check right diagonal pointing outwards from cell
	for(int i{row - 1}, j{col + 1}; i >= 0 and j < chessBoard.size(); --i, ++j)
		if(chessBoard.at(i).at(j))
			return false;
	
	// Return true if it satisfies all conditions
	return true;
}

// In these types of questions (matrix?)
// Paramaters represent level while options are represented by loops and/or if-else statements

// Approach 1: PepCoding solution (Brute Force Recursive Solution) (Apparently this is also the bactracking approach 😋)
void printNQueens(vector<vector<bool>>& chessBoard, int row = 0, vector<vector<int>> positions = {}){
	if(row == chessBoard.size()){
		for(const auto &position : positions)
			cout << position.front() << ' ' << position.back() << endl;
		cout << endl;
		return;
	}
	
	for(int col{}; col < chessBoard.size(); ++col)
		if(isValidPositon(chessBoard, row, col)){
			chessBoard.at(row).at(col) = 1;
			positions.push_back({row, col});
			printNQueens(chessBoard, row + 1, positions);
			positions.pop_back();
			chessBoard.at(row).at(col) = 0;
		}
	
}

// Approach 2,3,4 (for counting total number of ways for arranging n queens on n x n board)
// Link: https://leetcode.com/problems/n-queens-ii/discuss/1237811/Short-and-Easy-w-Explanation-and-Visualization-or-Backtracking-Explained!#:~:text=Solution%20%2D%20II%20(Backtracking%20O(N)%20Space)

int main(){
	cout << "Enter size of chessboard: ";
	int n; cin >> n;
	
	cout << "Possible positions to place " << n << " queens are given by: " << endl;
	vector<vector<bool>> chessBoard(n, vector<bool>(n));
	printNQueens(chessBoard);
}
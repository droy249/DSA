// Question Link: https://www.pepcoding.com/resources/online-java-foundation/recursion-backtracking/knights-tour-official/ojquestion
// Video Link: https://youtu.be/SP880DBRJ_8?list=PL-Jc9J83PIiFxaBahjslhBD1LiJAV7nKs
#include <iostream>
#include <vector>
using namespace std;

// To match the solution of pepCoding OJ, check for possibilities of moving khight from a cell (i,j) in the following order:
// (i - 2, j + 1) -> (i - 1, j + 2) -> (i + 1, j + 2) ->  (i + 2, j + 1) -> (i + 2, j - 1) -> (i + 1, j - 2) -> (i - 1, j - 2) -> (i - 2, j - 1)
void printKnightsTour(vector<vector<int>>& chessBoard, int row, int col, int move = 1){
	if(row < 0 or col < 0 or row >= chessBoard.size() or col >= chessBoard.size() or chessBoard[row][col] > 0) return;
	else if(move == chessBoard.size() * chessBoard.size() ){
		chessBoard[row][col] = move;
		for(const vector<int>& row : chessBoard){
			for(const auto& cell : row)
				cout << cell << ' ';
			cout << endl;
		}
		chessBoard[row][col] = 0;
		cout << endl;
		return;
	}
	chessBoard[row][col] = move;
	printKnightsTour(chessBoard, row - 2, col + 1, move + 1);
	printKnightsTour(chessBoard, row - 1, col + 2, move + 1);
	printKnightsTour(chessBoard, row + 1, col + 2, move + 1);
	printKnightsTour(chessBoard, row + 2, col + 1, move + 1);
	printKnightsTour(chessBoard, row + 2, col - 1, move + 1);
	printKnightsTour(chessBoard, row + 1, col - 2, move + 1);
	printKnightsTour(chessBoard, row - 1, col - 2, move + 1);
	printKnightsTour(chessBoard, row - 2, col - 1, move + 1);
	chessBoard[row][col] = 0;
}

int main(){
	cout << "Enter size of chessboard: ";
	int n; cin >> n;
	
	cout << "Enter starting coordinates of knight: ";
	int row, col; cin >> row >> col;
	
	cout << endl << "Possible ways to traverse " << n << " X " << n << " chessboard: " << endl;
	vector<vector<int>> chessBoard(n, vector<int>(n));
	// for(const auto& row : chessBoard){
		// for(const auto& cell : row)
			// cerr << cell << ' ';
		// cerr << endl;
	// }
	printKnightsTour(chessBoard, row, col);
}
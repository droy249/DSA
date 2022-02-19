// Question Link: https://www.pepcoding.com/resources/online-java-foundation/recursion-backtracking/flood-fill-official/ojquestion
// Video Link: https://youtu.be/R1URUB6_y2k?list=PL-Jc9J83PIiFxaBahjslhBD1LiJAV7nKs
#include <iostream>
#include <vector>
using namespace std;

// PepCoding Solution (Brute Force Recursion) (No Optimizations)
void floodFill(vector<vector<short>>& maze, vector<vector<bool>>& visited, short row = 0, short col = 0, string path = ""){
	// Checking if cell exists and/or can be visited
	if(row < 0 or col < 0 or row == maze.size() or col == maze.front().size() or maze.at(row).at(col) or visited.at(row).at(col)) return;
	
	// Returning path after reaching the end
	if(row == maze.size() - 1 and col == maze.front().size() - 1){
		cout << path << endl;
		return;
	}
	
	// Marking cell for visiting it
	visited.at(row).at(col) = true;
	
	// Exploring upper cell (if exists)
	floodFill(maze, visited, row - 1, col, path + 't');
	
	// Exploring left cell (if exists)
	floodFill(maze, visited, row, col - 1, path + 'l');
	
	// Exploring lower cell (if exists)
	floodFill(maze, visited, row + 1, col, path + 'd');
	
	// Exploring right cell (if exists)
	floodFill(maze, visited, row, col + 1, path + 'r');
	
	// Unmarking cell after visiting so that it can be revisited for a different path (if exists)
	visited.at(row).at(col) = false;
}

int main(){
	short rows, columns;
	cout << "Enter number of rows: ";
	cin >> rows;
	cout << "Enter number of columns: ";
	cin >> columns;
	
	vector<vector<short>> maze(rows, vector<short>(columns));
	vector<vector<bool>> visited(rows,vector<bool>(columns, 0));
	
	cout << endl << "Enter elements of the maze:" << endl;
	for(short i{}; i < rows; ++i)
		for(short j{}; j < columns; ++j)
			cin >> maze.at(i).at(j);
	
	// Can also do from (0,0) to (rows-1,columns-1). Doesn't affect solution and logic.
	cout << endl << "All possible paths within the given maze are:" << endl;
    floodFill(maze, visited);
}
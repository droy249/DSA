// Question Link: https://www.pepcoding.com/resources/online-java-foundation/recursion-with-arraylists/get-maze-path-with-jumps-official/ojquestion
// Video Link: https://youtu.be/VaGBRiSdtFI?list=PL-Jc9J83PIiFxaBahjslhBD1LiJAV7nKs
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// sr - source row
// sc - source column
// dr - destination row
// dc - destination column
vector <string> getMazePaths(short sr, short sc, const short& dr, const short& dc) {
	if(sr == dr and sc == dc) return {""};
	
	vector<string> pathsFromCurrentCell;
	
	// Horizontal Direction
	for(short i{1}; i <= dc - sc; ++i)
		for(const string& path : getMazePaths(sr, sc + i, dr, dc))
			pathsFromCurrentCell.push_back('h' + to_string(i) + path);
	
	// Vertical Direction
	for(short i{1}; i <= dr - sr; ++i)
		for(const string& path : getMazePaths(sr + i, sc, dr, dc))
			pathsFromCurrentCell.push_back('v' + to_string(i) + path);
	
	// Diagonal Direction
	for(short i{1}; i <= dc - sc and i <= dr - sr; ++i)
		for(const string& path : getMazePaths(sr + i, sc + i, dr, dc))
			pathsFromCurrentCell.push_back('d' + to_string(i) + path);
	
	return pathsFromCurrentCell;
}

int main() {
    short rows, columns;
	cout << "Enter number of rows: ";
	cin >> rows;
	cout << "Enter number of columns: ";
	cin >> columns;
	
	// Can also do from (1,1) to (rows,columns). Doesn't affect solution and logic.
	cout << "All possible paths from (1,1) to (" << rows << "," << columns << ") are:" << endl;
    for(const string& path: getMazePaths(1, 1, rows, columns)) 							
		cout << path << endl;
}
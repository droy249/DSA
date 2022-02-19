// Question Link: https://www.pepcoding.com/resources/online-java-foundation/recursion-with-arraylists/get-maze-paths-official/ojquestion
// Video Link: https://www.youtube.com/watch?v=7i41gZLXe5k&list=PL-Jc9J83PIiFxaBahjslhBD1LiJAV7nKs&index=31
#include<iostream>
#include<vector>

using namespace std;

// sr - source row
// sc - source column
// dr - destination row
// dc - destination column

// Approach 1: Navigate from source to destination, i.e. dr and dc remain unchanged while sr and sc are changed.
vector <string> getMazePaths(int sr, int sc, const int& dr, const int& dc) {
	if(sr == dr and sc == dc) return {""};
	
	vector<string> pathsFromCurrentCell;
	
	if(sc + 1 <= dc)
		for(const string& path : getMazePaths(sr, sc + 1, dr, dc))
			pathsFromCurrentCell.push_back('h' + path);
	
	if(sr + 1 <= dr)
		for(const string& path : getMazePaths(sr + 1, sc, dr, dc))
			pathsFromCurrentCell.push_back('v' + path);
	
	return pathsFromCurrentCell;
}

// // Aproach 2: Navigate from destination to source, i.e. sr and sc remain unchanged while dr and dc are changed.
// vector<string> getMazePaths(const int& sr, const int& sc, int dr, int dc){
	// if(sr == dr and sc == dc) return {""};
	
	// vector<string> pathsToCurrentCell;
	
	// if(sc <= dc - 1)
		// for(const string& path : getMazePaths(sr, sc, dr, dc - 1))
			// pathsToCurrentCell.push_back(path + 'h');
	
	// if(sr <= dr - 1)
		// for(const string& path : getMazePaths(sr, sc, dr - 1, dc))
			// pathsToCurrentCell.push_back(path + 'v');
	
	// return pathsToCurrentCell;
// }

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
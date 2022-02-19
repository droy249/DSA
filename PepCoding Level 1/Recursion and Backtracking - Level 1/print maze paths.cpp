// Question Link: https://www.pepcoding.com/resources/online-java-foundation/recursion-on-the-way-up/print-maze-paths-official/ojquestion
// Video Link: https://youtu.be/TcCyI-eJMmY?list=PL-Jc9J83PIiFxaBahjslhBD1LiJAV7nKs
#include <iostream>

// sr - source row
// sc - source column
// dr - destination row
// dc - destination column

// Approach 1: My solution
void printMazePaths(short sr, short sc, const short& dr, const short& dc, std::string path = ""){
	if(sc == dc and sr == dr){
		std::cout << path << std::endl;
		return;
	}
	if(sr + 1 <= dr) printMazePaths(sr + 1, sc, dr, dc, path + 'v');
	if(sc + 1 <= dc) printMazePaths(sr, sc + 1, dr, dc, path + 'h');
}

// // Approach 2: PepCoding Solution
// void printMazePaths(short sr, short sc, const short& dr, const short& dc, std::string path = ""){
	// if(sr > dr or sc > dc) return;
	// else if(sc == dc and sr == dr){
		// std::cout << path << std::endl;
		// return;
	// }
	// printMazePaths(sr, sc + 1, dr, dc, path + 'h');
	// printMazePaths(sr + 1, sc, dr, dc, path + 'v');
// }

int main(){
	short rows, columns;
	std::cout << "Enter number of rows: ";
	std::cin >> rows;
	std::cout << "Enter number of columns: ";
	std::cin >> columns;
	
	// Can also do from (1,1) to (rows,columns). Doesn't affect solution and logic.
	std::cout << "All possible paths from (1,1) to (" << rows << "," << columns << ") are:" << std::endl;
    printMazePaths(1, 1, rows, columns);
}
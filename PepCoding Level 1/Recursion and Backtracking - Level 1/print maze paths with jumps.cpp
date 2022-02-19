// Question Link: https://www.pepcoding.com/resources/online-java-foundation/recursion-on-the-way-up/print-maze-path-with-jumps-official/ojquestion
// Video Link: https://youtu.be/zri_tftYphE?list=PL-Jc9J83PIiFxaBahjslhBD1LiJAV7nKs
#include <iostream>
#include <string>

// sr - source row
// sc - source column
// dr - destination row
// dc - destination column
void printMazePaths(short sr, short sc, const short& dr, const short& dc, std::string path = ""){
	if(sr == dr and sc == dc) {
		std::cout << path << std::endl;
		return;
	}
	
	// Horizontal Direction
	for(short i{1}; i <= dc - sc; ++i)
		printMazePaths(sr, sc + i, dr, dc, path + 'h' + std::to_string(i));
	
	// Vertical Direction
	for(short i{1}; i <= dr - sr; ++i)
		printMazePaths(sr + i, sc, dr, dc, path + 'v' + std::to_string(i));
	
	// Diagonal Direction
	for(short i{1}; i <= dc - sc and i <= dr - sr; ++i)
		printMazePaths(sr + i, sc + i, dr, dc, path + 'd' + std::to_string(i));
}

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
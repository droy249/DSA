// Question Link:https://www.pepcoding.com/resources/online-java-foundation/recursion-on-the-way-up/print-stair-paths-official/ojquestion
// Video Link: https://youtu.be/JxIoGHzzoW8?list=PL-Jc9J83PIiFxaBahjslhBD1LiJAV7nKs
#include <iostream>

void printStairPaths(short n, std::string path = ""){
	if(!n) {
		std::cout << path << std::endl;
		return;
	}
	if(n >= 1) printStairPaths(n - 1, path + '1');
	if(n >= 2) printStairPaths(n - 2, path + '2');
	if(n >= 3) printStairPaths(n - 3, path + '3');
}

int main(){
	short n;
	std::cout << "Enter number of steps: ";
	std::cin >> n;
	std::cout << "The paths that can be used to climb the staircase up are: " << std::endl;
	printStairPaths(n);
}
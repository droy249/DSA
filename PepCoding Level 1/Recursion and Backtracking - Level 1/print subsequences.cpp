// Write a recursive program to print all subsequences of a string.
// Question Link: https://www.pepcoding.com/resources/online-java-foundation/recursion-on-the-way-up/print-subsequence-official/ojquestion
// Video Link: https://youtu.be/Ke8TPhHdHMw?list=PL-Jc9J83PIiFxaBahjslhBD1LiJAV7nKs
#include <iostream>

// // Appoach 1: PepCoding Version
// void printSubsequences(std::string givenString, std::string subString = ""){
	// if(givenString.empty()) {
		// std::cout << subString << std::endl;
		// return;
	// }
	// printSubsequences(givenString.substr(1), subString + givenString.front());
	// printSubsequences(givenString.substr(1), subString);
// }

// Approach 2: Maintaining an index for substring of givenString
void printSubsequences(const std::string& givenString, size_t i = 0, std::string subString = ""){
	if(i == givenString.length()) {
		std::cout << subString << std::endl;
		return;
	}
	printSubsequences(givenString, i + 1, subString + givenString.at(i));
	printSubsequences(givenString, i + 1, subString);
}

int main(){
	std::string givenString;
	std::cout << "Enter string: ";
	std::getline(std::cin, givenString);
	
	std::cout << "Subsequences of given string are: " << std::endl;
	printSubsequences(givenString);
}
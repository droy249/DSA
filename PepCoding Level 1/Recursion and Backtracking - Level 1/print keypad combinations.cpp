// Question Link: https://www.pepcoding.com/resources/online-java-foundation/recursion-on-the-way-up/print-kpc-official/ojquestion
// Video Link: https://youtu.be/4yMtvToiJE0?list=PL-Jc9J83PIiFxaBahjslhBD1LiJAV7nKs
#include <iostream>

const std::string CODES[] = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};

// // Approach 1: PepCoding Version
// void printKeyPadCodes(std::string givenCode, std::string subString = ""){
	// if(givenCode.empty()){
		// std::cout << subString << std::endl;
		// return;
	// }
	
	// for(const char& code : CODES[givenCode.front() - '0'])
		// printKeyPadCodes(givenCode.substr(1), subString + code);
// }

// Approach 2: Maintaining an index for substring of givenCode
void printKeyPadCodes(const std::string& givenCode, size_t i = 0, std::string subString = ""){
	if(i == givenCode.length()){
		std::cout << subString << std::endl;
		return;
	}
	
	for(const char& code : CODES[givenCode.at(i) - '0'])
		printKeyPadCodes(givenCode, i + 1, subString + code);
}

int main(){
	std::string givenCode; 
	std::cout << "Enter your code: ";
	std::getline(std::cin, givenCode);
	
	std::cout << "Possible combinations of given code can be: " << std::endl;
	printKeyPadCodes(givenCode);
}
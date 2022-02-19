// Question Link: https://www.pepcoding.com/resources/online-java-foundation/recursion-with-arraylists/get-kpc-official/ojquestion
// Video Link: https://youtu.be/3fjt19bjs3A?list=PL-Jc9J83PIiFxaBahjslhBD1LiJAV7nKs
#include <iostream>
#include <vector>

using namespace std;

const string CODES[] = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};

vector<string> getKeyPadCodes(string givenCode){
	if(givenCode.empty()) return {""};
	vector<string> recursionResult{getKeyPadCodes(givenCode.substr(1))};
	vector<string> currentResult;
	
	for(const char& code : CODES[givenCode.front() - '0'])
		for(string& result : recursionResult)
			currentResult.emplace_back(code + result);
		
	return currentResult;
}

int main(){
	string givenCode; 
	cout << "Enter your code: ";
	getline(cin, givenCode);
	
	cout << "Possible combinations of given code can be: " << endl;
	for(const string& keyPadCode : getKeyPadCodes(givenCode))
		cout << keyPadCode << endl;
}
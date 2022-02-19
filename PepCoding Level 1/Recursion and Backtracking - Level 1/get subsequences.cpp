// Program to find all subsequences of a string using recursion
// Video Link: https://youtu.be/Sa5PmCFF_zI?list=PL-Jc9J83PIiFxaBahjslhBD1LiJAV7nKs&t=586
#include <iostream>
#include <vector>

using namespace std;

// // Approach 1: PepCoding Approach
// vector<string> getSubsequences(string myString){
	// if(myString.empty()) return {{}};

	// vector<string> recursionResult{getSubsequences(myString.substr(1))};
	
	// vector<string> myResult{recursionResult};

	// for(const string& str: recursionResult
		// myResult.emplace_back(myString.front() + str);
	
	// return myResult;
// }

// Approach 2: based of Approach 1
vector<string> getSubsequences(const string& myString, size_t index = 0){
	if(index == myString.size()) return {""}; // or return {{}};

	vector<string> recursionResult{getSubsequences(myString, index + 1)};
	
	vector<string> myResult{recursionResult};

	for(const string& str: recursionResult)
		myResult.emplace_back(myString.at(index) + str);
	
	return myResult;
}

// Approach 3: Call a helper function of void type. 

// Approach 4: Aditya Verma Approach

int main(){
	string givenString;
	cout << "Enter string: ";
	getline(cin, givenString);
	
	cout << "Subsequences of given string are: " << endl;
	for(const string& subsequence : getSubsequences(givenString))
		cout << subsequence << endl;
}
// Question Link: https://www.pepcoding.com/resources/online-java-foundation/recursion-on-the-way-up/print-permutations-official/ojquestion
// Video Link: https://youtu.be/sPAT_DbvDj0?list=PL-Jc9J83PIiFxaBahjslhBD1LiJAV7nKs
// Equivalent Leetcode link: https://leetcode.com/problems/permutations/
#include <iostream>
using namespace std;

// Approach 1: PepCoding solution
void printPermutations(const string givenString, string permutation = ""){
	if(givenString.empty()){
		cout << permutation << endl;
		return;
	}
	
	for(size_t i{}; i < givenString.length(); ++i)
		printPermutations(givenString.substr(0,i) + givenString.substr(i+1), permutation + givenString.at(i));
}

int main(){
	string givenString;
	cout << "Enter string: ";
	getline(cin, givenString);
	
	cout << "Permutations of given string are: " << endl;
	printPermutations(givenString);
}
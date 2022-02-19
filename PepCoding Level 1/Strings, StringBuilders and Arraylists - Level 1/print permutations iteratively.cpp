// Question Link: 
// Video Link: 
// Leetcode problem link: 
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void printPermutations(const string& s){
	int factorial{(int)tgamma(s.size() + 1)};
	
	for(int f{}; f < factorial; ++f){
		string tempString{s};
		int temp{f};
		
		for(int divisor{(int)s.size()}; divisor; --divisor){
			int index{temp % divisor};
			cout << tempString.at(index);
			// tempString = tempString.substr(0, index) + tempString.substr(index + 1);
			tempString.erase(begin(tempString) + index);
			temp /= divisor;
		}
		cout << ' ';
	}
}

int main(){
	cout << "Enter a string: ";
	string s; cin >> s;
	printPermutations(s);
}
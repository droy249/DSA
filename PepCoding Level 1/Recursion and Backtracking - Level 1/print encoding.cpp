// Question Link: https://www.pepcoding.com/resources/online-java-foundation/recursion-on-the-way-up/print-encodings-official/ojquestion
// Video Link: https://youtu.be/2ClSccwnq1Y?list=PL-Jc9J83PIiFxaBahjslhBD1LiJAV7nKs
#include <iostream>
using namespace std;

void printEncoding(string encoded, string decoded = ""){
	if(encoded.front() == '0') 
		return;
	
	if(encoded.empty()){
		cout << decoded << endl;
		return;
	}
	
	printEncoding(encoded.substr(1), decoded + char(encoded.front() - '1' + 'a'));
	
	if(encoded.size() > 1 and (encoded.front() == '1' or (encoded.front() == '2' and encoded.at(1) < '7')))
		printEncoding(encoded.substr(2), decoded + char(stoi(encoded.substr(0,2)) - 1 + 'a'));
}

int main(){
	string givenString;
	cout << "Enter encoded message: ";
	cin >> givenString;
	
	cout << "The possible decoded messages are: " << endl;
	printEncoding(givenString);
}
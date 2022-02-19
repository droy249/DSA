// Question Link: https://www.pepcoding.com/resources/online-java-foundation/recursion-with-arraylists/get-stair-paths-official/ojquestion
// Video Link: https://youtu.be/hMJAlbJIS7E?list=PL-Jc9J83PIiFxaBahjslhBD1LiJAV7nKs
#include <iostream>
#include <vector>

using namespace std;

vector<string> getStairPaths(short n){
	if(!n) return {""};
	
	vector<string> myResult;
	if(n >= 3)
		for(const string& path : getStairPaths(n - 3))
			myResult.push_back('3' + path);
		
	if(n >= 2)
		for(const string& path : getStairPaths(n - 2))
			myResult.push_back('2' + path);
	
	if(n >= 1)
		for(const string& path : getStairPaths(n - 1))
			myResult.push_back('1' + path);
	
	return myResult;
}

int main(){
	// uint8_t n; 
	// unsigned __int8 i; 
	short n;
	cout << "Enter number of steps: ";
	cin >> n;
	cout << "The paths that can be used to climb the staircase up are: " << endl;
	for(const string& path : getStairPaths(n))
		cout << path << endl;
}
#include <iostream>
#include <set>
#include <string>
// #include <algorithm>
using namespace std;

// void uniqueSubsequences(set<string>& all_substring, string input, string output) {
    // if(input.empty() && find(all_substring.begin(), all_substring.end(), output) == all_substring.end()) {
        // all_substring.push_back(output);
        // return;
    // }
    // string output1(output), output2(output);
    // output2.push_back(input.front());
    // // output2.insert(output2.begin() ,input.back());
    // input.erase(input.begin());
    // input.pop_back();
    // uniqueSubsequences(all_substring, input, output1);
    // uniqueSubsequences(all_substring, input, output2);
// }

void uniqueSubsequences(set<string>& all_substring, string &input, string output, size_t i = 0){
	if(i == input.length()){
		all_substring.insert(begin(all_substring), output);
		return;
	}
	uniqueSubsequences(all_substring, input, output + input.at(i), i + 1);
	uniqueSubsequences(all_substring, input, output, i + 1);
}

int main() {
    string input_string;
    cout << "Enter input string: ";
    getline(cin, input_string);
    set<string> all_substrings;
    uniqueSubsequences(all_substrings, input_string, "");
    for (const string &substring : all_substrings) cout << substring << " ";
    cout << endl;
	// system("pause");
}
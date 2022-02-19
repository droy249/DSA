#include <iostream>
#include <vector>
#include <string>
using namespace std;

// void allSubsequences(vector<string>& all_substring, string input, string output) {
    // if(input.empty()) {
        // all_substring.push_back(output);
        // return;
    // }
    // string output1(output), output2(output);
    // // output2.push_back(input.front());
    // output2.insert(output2.begin() ,input.back());
    // // input.erase(input.begin());
    // input.pop_back();
    // allSubsequences(all_substring, input, output1);
    // allSubsequences(all_substring, input, output2);
// }

void allSubsequences(vector<string>& all_substring, string &input, string output, size_t i = 0){
	if(i == input.length()){
		all_substring.emplace_back(output);
		return;
	}
	allSubsequences(all_substring, input, output + input.at(i), i + 1);
	allSubsequences(all_substring, input, output, i + 1);
}

int main() {
    string input_string;
    cout << "Enter input string: ";
    getline(cin, input_string);
    vector<string> all_substrings;
    allSubsequences(all_substrings, input_string, "");
    for (const string &substring : all_substrings) {
        cout << substring << " ";
    }
    cout << endl;
	system("pause");
}

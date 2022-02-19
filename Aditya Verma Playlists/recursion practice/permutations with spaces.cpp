#include <iostream>
#include <vector>
#include <string>
using namespace std;

void permutationsWithSpaces(vector<string>& all_permutations, string input, string output) {
    if(input.empty()) {
        all_permutations.push_back(output);
        return;
    } 
    string output1(output), output2(output);
    // output1.push_back(' ');
    // output1.push_back(input.front());
    // output2.push_back(input.front());

    /*
        Use either += or push_back() to append one character at a time. If done for strings, it will give error
        because += apparently doesn't add multiple string or charcters all at once, while push_back() is specifically
        meant to append only a single character

        append() doesn't work. emplace_back() does not exist.
    */
   
    output1 += ' ';
    output1 += input[0];
    output2 += input[0];
    input.erase(input.begin());
    permutationsWithSpaces(all_permutations, input, output1);
    permutationsWithSpaces(all_permutations, input, output2);
}

int main() {
    string input_string, output_string;
    cout << "Enter input string: ";
    getline(cin, input_string);
    output_string.push_back(input_string.front());
    input_string.erase(input_string.begin());
    vector<string> all_permutationss;
    permutationsWithSpaces(all_permutationss, input_string, output_string);
    for (const string &substring : all_permutationss)
        cout << substring << "\n";
    return 0;
}

#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

void permutations_with_case_change(vector<string>& all_permutations, string input, string output) {
    if(input.empty()) {
        all_permutations.push_back(output);
        return;
    }
    if(!isdigit(input.front())) {
        string output1(output), output2(output);
        output1.push_back(islower(input.front()) ? toupper(input.front()) : input.front());
        output2.push_back(isupper(input.front()) ? tolower(input.front()) : input.front());
        input.erase(input.begin());
        permutations_with_case_change(all_permutations, input, output1);
        permutations_with_case_change(all_permutations, input, output2);
    } else {
        output.push_back(input.front());
        input.erase(input.begin());
        permutations_with_case_change(all_permutations, input, output);
    }
    return;
}

int main() {
    string input_string;
    cout << "Enter input string: ";
    getline(cin, input_string);
    vector<string> all_permutationss;
    permutations_with_case_change(all_permutationss, input_string, "");
    for (const string &substring : all_permutationss) {
        cout << substring << " ";
    }
    cout << endl;
}

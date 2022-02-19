#include <iostream>
#include <algorithm> 
using namespace std;

// void replacePi(string& s) {
//     if(s.empty()) return;
//     if(s[0] == 'p' and s[i] == 'i') {
//         s.replace(0, "3.14");
//         replacePi(s.substr(2));
//     }
// }

int main() {
    string s("pippppppiiip");
    // replacePi(s);
    replace_if(s.begin(), s.end(), "pi", "3,14");
    cout << s;
}
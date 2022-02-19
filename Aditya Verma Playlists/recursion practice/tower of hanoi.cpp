#include <iostream>
using namespace std;

void towerOfHanoi(int n, char source, char helper, char destination, int& count) {
    ++count;
    if(n == 1) {
        cout << "Step " << count << ": Moving disk " << n << " from " << source << " to " << destination << endl;
        return;
    }
    towerOfHanoi(n - 1, source, destination, helper, count);
    cout << "Step " << count << ": Moving disk " << n << " from " << source << " to " << destination << endl;
    towerOfHanoi(n - 1, helper, source, destination, count);
}

int main() {
    int n = 4, c = 0;
    cout << "Enter number of disks: ";
    cin >> n;
    towerOfHanoi(n, 'S', 'H', 'D', c);
    return 0;
}
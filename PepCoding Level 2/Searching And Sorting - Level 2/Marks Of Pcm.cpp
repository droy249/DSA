// Question Link: https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/searching-and-sorting/marks_of_pcm/ojquestion
// Video Link: https://youtu.be/aGMzcfWsdWE?list=PL-Jc9J83PIiHhXKonZxk7gbEWsmSYP5kq
// Gfg Practice Link: https://practice.geeksforgeeks.org/problems/marks-of-pcm2529/1
#include <bits/stdc++.h>
using namespace std;

void customSort(int phy[], int chem[], int math[], int N) {
    array<int, 3> arr[N];

    for (int i = 0; i < N; i++) {
        arr[i] = {phy[i], chem[i], math[i]};
    }

    sort(arr, arr + N, [](auto& a, auto& b) {
        if (a[0] == b[0] && a[1] == b[1])
            return a[2] < b[2];
        else if (a[0] == b[0])
            return a[1] > b[1];
        else
            return a[0] < b[0];
    });

    for (int i = 0; i < N; i++) {
        phy[i] = arr[i][0];
        chem[i] = arr[i][1];
        math[i] = arr[i][2];
    }
}

int main() {
    int n;
    cin >> n;
    int phy[n], chem[n], math[n];

    cout << "\nEnter marks: \n";
    for (int i = 0; i < n; ++i) {
        cin >> phy[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> chem[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> math[i];
    }

    customSort(phy, chem, math, n);

    cout << "\nSorted marks: \n";
    for (int i = 0; i < n; i++) {
        cout << phy[i] << " " << chem[i] << " " << math[i] << "\n";
    }
}

/* Input:
10
14 1 10 3 4 2 1 10 1 11
5 12 9 6 3 10 2 9 14 10
12 3 6 5 2 10 16 32 10 4
 */

/* Output:
1 14 10
1 12 3
1 2 16
2 10 10
3 6 5
4 3 2
10 9 6
10 9 32
11 10 4
14 5 12
 */
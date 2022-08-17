// Question Link: https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/searching-and-sorting/union_of_two_sorted_arrays/ojquestion
// Video Link: https://youtu.be/JCT04Z94Nyo?list=PL-Jc9J83PIiHhXKonZxk7gbEWsmSYP5kq
// Gfg Link: 
// Practice Link: https://practice.geeksforgeeks.org/problems/union-of-two-sorted-arrays/1
#include <bits/stdc++.h>
using namespace std;

vector<int> findUnion(int arr1[], int arr2[], int n, int m) {
    vector<int> ans;

    int i = 0, j = 0;
    while (i < n && j < m) {
        if (i > 0 && arr1[i - 1] == arr1[i]) {
            ++i;
            continue;
        }

        if (j > 0 && arr2[j - 1] == arr2[j]) {
            ++j;
            continue;
        }

        if (arr1[i] < arr2[j]) {
            ans.push_back(arr1[i]);
            ++i;
        } else if (arr1[i] > arr2[j]) {
            ans.push_back(arr2[j]);
            ++j;
        } else {
            ans.push_back(arr1[i]);
            ++i;
            ++j;
        }
    }

    while (i < n) {
        if (arr1[i - 1] == arr1[i]) {
            ++i;
            continue;
        }
        ans.push_back(arr1[i++]);
    }

    while (j < m) {
        if (j > 0 && arr2[j - 1] == arr2[j]) {
            ++j;
            continue;
        }
        ans.push_back(arr2[j++]);
    }

    return ans;
}

int main() {
    int a[] = {1, 1, 1, 2, 2, 7, 9, 9};
    int b[] = {1, 1, 3, 3, 7, 8, 8, 8};

    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);

    cout << "\nUnion: ";
    for (auto &&num : findUnion(a, b, n, m))
        cout << num << " ";
    cout << "\n";
}
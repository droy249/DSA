// Gfg Link: https://www.geeksforgeeks.org/union-and-intersection-of-two-sorted-arrays-2/
#include <stdio.h>

// Time Complexity : O(n1 + n2)
// Space Complexity: O(1)
void printIntersection(int a[], int n1, int b[], int n2) {
    if (a == NULL || n1 == 0 || b == NULL || n2 == 0) {
        return;
    }

    printf("\nIntersection: ");

    int i = 0, j = 0;
    while (i < n1 && j < n2) {
        if (a[i] < b[j]) {
            ++i;
        } else if (a[i] > b[j]) {
            ++j;
        } else {
            printf("%d ", a[i]);
            ++i;
            ++j;
        }
    }
    printf("\n");
}

// Time Complexity : O(n1 + n2)
// Space Complexity: O(1)
void printUnion(int a[], int n1, int b[], int n2) {
    if (a == NULL || n1 == 0 || b == NULL || n2 == 0) {
        return;
    }

    printf("\nUnion: ");

    int i = 0, j = 0;

    // Prints via comparing elements
    // Runs for O(min(n1,n2))
    while (i < n1 && j < n2) {
        if (i > 0 && a[i - 1] == a[i]) {
            ++i;
            continue;
        }
        if (j > 0 && b[j - 1] == b[j]) {
            ++j;
            continue;
        }

        if (a[i] < b[j]) {
            printf("%d ", a[i]);
            ++i;
        }  if (a[i] > b[j]) {
            printf("%d ", b[j]);
            ++j;
        }  if(a[i] == b[j]) {
            printf("%d ", a[i]);
            ++i;
            ++j;
        }
    }

    // Print the remaining elements in the longer array
    while (i < n1) {
        if (i == 0 || a[i - 1] != a[i]) {
            printf("%d ", a[i]);
            ++i;
        }
    }

    while (j < n2) {
        if (j == 0 || b[j - 1] != b[j]) {
            printf("%d ", b[j]);
            ++j;
        }
    }

    printf("\n");
}

void UnionArray(int arr1[], int arr2[], int l1, int l2) {
    // Taking max element present in either array
    int m = arr1[l1 - 1];
    int n = arr2[l2 - 1];
    int ans = 0;
    if (m > n)
        ans = m;
    else
        ans = n;

    // Finding elements from 1st array (non duplicates
    // only). Using another array for storing union elements
    // of both arrays Assuming max element present in array
    // is not more than 10^7
    int newtable[ans + 1];
    for (int i = 0; i < ans + 1; i++)
        newtable[i] = 0;
    // First element is always present in final answer
    printf("%d ", arr1[0]);

    // Incrementing the First element's count in it's
    // corresponding index in newtable
    ++newtable[arr1[0]];

    // Starting traversing the first array from 1st index
    // till last
    for (int i = 1; i < l1; i++) {
        // Checking whether current element is not equal to
        // it's previous element
        if (arr1[i] != arr1[i - 1]) {
            printf("%d ", arr1[i]);
            ++newtable[arr1[i]];
        }
    }

    // Finding only non common elements from 2nd array
    for (int j = 0; j < l2; j++) {
        // By checking whether it's already resent in
        // newtable or not
        if (newtable[arr2[j]] == 0) {
            printf("%d ", arr2[j]);
            ++newtable[arr2[j]];
        }
    }
}

int main() {
    int a[] = {1, 1, 2, 2};  //{1, 3, 3, 5, 7};
    int b[] = {2, 2};        //{2, 3, 5, 6};

    int n1 = sizeof(a) / sizeof(a[0]);
    int n2 = sizeof(b) / sizeof(b[0]);

    printIntersection(a, n1, b, n2);
    printUnion(a, n1, b, n2);
    // UnionArray(a, b, n1, n2);
}
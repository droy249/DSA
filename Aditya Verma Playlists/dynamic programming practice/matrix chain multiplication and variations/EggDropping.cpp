// Leetcode Link: https://leetcode.com/problems/super-egg-drop/
#include <bits/stdc++.h>
using namespace std;

// Video Link: https://youtu.be/S49zeUjeUL0?list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go
int recursive(int eggs, int floors) {
    if (floors < 2 || eggs == 1) {
        return floors;
    }

    int minMoves = INT_MAX;

    for (int floor = 1; floor <= floors; floor++) {
        // Here we use max() because we wish to calculate keeping the worst case scenario in our mind
        int moves = 1 + max(recursive(eggs - 1, floor - 1), recursive(eggs, floors - floor));

        // Finally we use min() because we need to find the minimum number of moves
        minMoves = min(minMoves, moves);
    }

    return minMoves;
}

// Video Link: https://youtu.be/jkygQmOiCCI?list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go
int memoize(int eggs, int floors, vector<vector<int>>& cache) {
    // Base case
    if (floors < 2 || eggs == 1) {
        return cache[eggs][floors] = floors;
    }

    // Check if already exists in cache
    if (cache[eggs][floors] != -1) {
        return cache[eggs][floors];
    }

    int minMoves = INT_MAX;

    for (int floor = 1; floor <= floors; floor++) {
        // Here we use max() because we wish to calculate keeping the worst case scenario in our mind
        int moves = 1 + max(memoize(eggs - 1, floor - 1, cache), memoize(eggs, floors - floor, cache));

        // Finally we use min() because we need to find the minimum number of moves
        minMoves = min(minMoves, moves);
    }

    return cache[eggs][floors] = minMoves;
}

int memoizeWithBinarySearch(int eggs, int floors, vector<vector<int>>& cache) {
    // Base case
    if (floors < 2 || eggs == 1) {
        return cache[eggs][floors] = floors;
    }

    // Check if already exists in cache
    if (cache[eggs][floors] != -1) {
        return cache[eggs][floors];
    }

    int low = 1, high = floors;
    int minMoves = INT_MAX;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        // Case 1: Egg breaks when dropped
        int moves1 = memoizeWithBinarySearch(eggs - 1, mid - 1, cache);

        // Case 2: Egg does not break when dropped
        int moves2 = memoizeWithBinarySearch(eggs, floors - mid, cache);
        
        // Here we use max() because we wish to calculate keeping the worst case scenario in our mind
        int moves = max(moves1, moves2) + 1;

        // Finally we use min() because we need to find the minimum number of moves
        minMoves = min(minMoves, moves);
        
        // If the egg breaks, then we need to reduce the search space to the floors ABOVE this floor
        if (moves1 > moves2)
            high = mid - 1;
        
        // Else if the egg does not break, then we need to reduce the search space to the floors BELOW this floor
        else
            low = mid + 1;
    }

    return cache[eggs][floors] = minMoves;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int eggs = 3, floors = 14;
    vector<vector<int>> cache1(eggs + 1, vector<int>(floors + 1, -1)), cache2(cache1);

    printf("\nThe minimum number of moves that you need to determine with certainty what the value of critical floor is:\n");
    // printf("Recursive: %d\n", recursive(eggs, floors));
    printf("Memoized: %d\n", memoize(eggs, floors, cache1));
    printf("Memoized + Binary Search: %d\n", memoizeWithBinarySearch(eggs, floors, cache2));
}
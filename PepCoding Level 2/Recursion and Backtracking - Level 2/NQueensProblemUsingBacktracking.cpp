// Video Link: https://youtu.be/yvt0emtFiIE?list=PL-Jc9J83PIiHO9SQ6lxGuDsZNt2mkHEn0
// Question Link: https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/nqueens-branch-and-bound-official/ojquestion
// Gfg Link: https://www.geeksforgeeks.org/n-queen-problem-using-branch-and-bound/
// Leetcode Link: https://leetcode.com/problems/n-queens/
#include <bits/stdc++.h>
using namespace std;

void solve(int row, vector<vector<bool>>& board, vector<bool>& cols, vector<bool>& normalDiag, vector<bool>& reverseDiag, vector<bool> ) {
    if(row == board.size()) {
        
    }
}

void nQueensBranchAndBound(int n) {
    vector<bool> cols(n), normalDiag(2 * n - 1), reverseDiag(2 * n - 1);
    vector<vector<bool>> board(n , vector<bool>(n));
    solve(0, board, cols, normalDiag, reverseDiag, {});
}

int main() {
    nQueensBranchAndBound(4);
}
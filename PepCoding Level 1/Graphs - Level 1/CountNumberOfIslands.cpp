// Question Link:
// Video Link:
#include <bits/stdc++.h>
using namespace std;

// Time Compexity: O(n^2)
// Space Complexity: O(n^2) , because of visited matrix
// Analysis: https://nados.io/article/number-of-islands#:~:text=4.-,Analysis,-%2D
class Solution {
   public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        int count = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '0' && !visited[i][j]) {
                    drawTreeForComponent(grid, i, j, visited);
                    ++count;
                }
            }
        }

        return count;
    }

    void drawTreeForComponent(vector<vector<char>>& arr, int i, int j, vector<vector<bool>>& visited) {
        if(i < 0 || i >= arr.size() || j < 0 || j >= arr[0].size() || visited[i][j] || arr[i][j] == '1') return;
        
        visited[i][j] = true;
        drawTreeForComponent(arr, i - 1, j, visited);
        drawTreeForComponent(arr, i, j + 1, visited);
        drawTreeForComponent(arr, i, j - 1, visited);
        drawTreeForComponent(arr, i + 1, j, visited);
        // visited[i][j] = false;
    }
};

int main() {
    vector<vector<char>> arr{
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}};

    Solution ob;
    cout << "Number of connected components: " << ob.numIslands(arr);
}
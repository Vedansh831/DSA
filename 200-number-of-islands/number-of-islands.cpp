class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& grid) {
        if(row < 0 || col < 0 ||  row >= grid.size() || col >= grid[0].size()) return;
        if(grid[row][col] != '1') return;
        // Mark as visited
        grid[row][col] = '0';
        dfs(row + 1, col, grid);
        dfs(row - 1, col, grid);
        dfs(row, col + 1, grid);
        dfs(row, col - 1, grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '1') {
                    ans++;
                    dfs(i, j, grid);
                }
            }
        }
        return ans;
    }
};
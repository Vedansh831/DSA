class Solution {
public:
    vector<vector<int>> visited;
    bool dfs(int row, int col, int parentRow, int parentCol,
        vector<vector<char>>& grid) {
        visited[row][col] = 1;
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        for (int k = 0; k < 4; k++) {
            int nr = row + dx[k];
            int nc = col + dy[k];
            if (nr < 0 || nr >= grid.size() ||
                nc < 0 || nc >= grid[0].size())
                continue;
            if (grid[nr][nc] != grid[row][col])
                continue;
            if (nr == parentRow && nc == parentCol)
                continue;
            if (visited[nr][nc])
                return true;
            if (dfs(nr, nc, row, col, grid))
                return true;
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        visited.assign(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j]) {
                    if (dfs(i, j, -1, -1, grid))
                        return true;
                }
            }
        }
        return false;
    }
};
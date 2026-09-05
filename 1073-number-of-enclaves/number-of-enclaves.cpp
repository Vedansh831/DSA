class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& grid){
        if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size()) return;
        if(grid[row][col]!=1) return;
        grid[row][col] = 0;
        dfs(row+1, col, grid);
        dfs(row-1, col, grid);
        dfs(row, col+1, grid);
        dfs(row, col-1, grid);
        return;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        for(int i=0;i<n;i++){
            dfs(i, 0, grid);
            dfs(i, m-1, grid);
        }
        for(int i=0;i<m;i++){
            dfs(0, i, grid);
            dfs(n-1, i, grid);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) ans++;
            }
        }
        return ans;
    }
};
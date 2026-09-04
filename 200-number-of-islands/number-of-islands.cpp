class Solution {
public:
    vector<vector<int>> visited;
    int result = 0;
    void f(vector<vector<char>>& grid, int r, int c){
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size()) return;
        if(grid[r][c] == '0' || visited[r][c]) return;
        visited[r][c] = 1;
        f(grid, r-1, c);
        f(grid, r+1, c);
        f(grid, r, c+1);
        f(grid, r, c-1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        visited.resize(n, vector<int>(m, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && visited[i][j]!=1){
                    result++;
                    f(grid, i, j);
                }
            }
        }
        return result;
    }
};
class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& ocean, vector<vector<int>>& heights, int prev){
        int n = heights.size();
        int m = heights[0].size();
        if(row < 0 || col < 0 || row >= n || col >= m) return;
        if(heights[row][col] < prev || ocean[row][col]==1) return;
        ocean[row][col] = 1;
        prev = heights[row][col];
        dfs(row+1, col, ocean, heights, prev);
        dfs(row-1, col, ocean, heights, prev);
        dfs(row, col+1, ocean, heights, prev);
        dfs(row, col-1, ocean, heights, prev);
        return;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> paci(n, vector<int>(m, 0)); 
        vector<vector<int>> atlan(n, vector<int>(m, 0));
        // Left side and Right side
        for(int i=0;i<n;i++){
            dfs(i, 0, paci, heights, -1);
            dfs(i, m-1, atlan, heights, -1);
        } 
        // Top side and Bottom side
        for(int i=0;i<m;i++){
            dfs(0, i, paci, heights, -1);
            dfs(n-1, i, atlan, heights, -1);
        }
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(paci[i][j] && atlan[i][j]) ans.push_back({i, j});
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m));
        queue<pair<int, int>> q; // Row, Column
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    ans[i][j] = 0;
                    q.push({i, j});
                }
                else ans[i][j] = INT_MAX;
            }
        }
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            int r = curr.first;
            int c = curr.second;
            for(int i=0;i<4;i++){
                int nr = r + dx[i];
                int nc = c + dy[i];

                if(nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
                if(ans[nr][nc] > ans[r][c] + 1){
                    ans[nr][nc] = ans[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
        return ans;
    }
};
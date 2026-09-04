class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int min = 0;
        int fo = 0;
        queue<pair<int, int>> q; // Row, Column
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) fo++;
                else if(grid[i][j]==2) q.push({i, j});
                else continue;
            }
        }
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        q.push({-1, -1}); // This is the check that first iteration is completed
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            int row = curr.first;
            int col = curr.second;
            if(row == -1 && col == -1){
                min++;
                if(!q.empty()) q.push({-1, -1});
                continue;
            }

            for(int i=0;i<4;i++){
                int nr = row + dx[i];
                int nc = col + dy[i];

                if(nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
                if(grid[nr][nc] == 2 || grid[nr][nc] == 0) continue;
                grid[nr][nc] = 2;
                fo--;
                q.push({nr, nc});
            }
        }
        if(fo==0) return min-1;
        return -1;
    }
};
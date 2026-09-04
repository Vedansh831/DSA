class Solution {
public:

    vector<vector<int>> visited;
    void dfs(int row, int col, queue<pair<int, int>>& q, vector<vector<int>>& grid){
        if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size()) return;
        if(grid[row][col] != 1 || visited[row][col] == 1) return;
        q.push({row, col});
        visited[row][col] = 1;
        dfs(row+1, col, q, grid);
        dfs(row-1, col, q, grid);
        dfs(row, col+1, q, grid);
        dfs(row, col-1, q, grid);
        return;
    }

    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        visited.assign(n, vector<int>(m, 0));
        bool find = false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    dfs(i, j, q, grid); // Taking all the ones of first bridge into the queue
                    find = true;
                    break;
                }
            }
            if(find) break;
        }

        // Now applying bfs till i will get the one from another side
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        int ans = 0;
        while(!q.empty()){
            int size = q.size();
            ans++;
            while(size--){
                auto curr = q.front();
                q.pop();
                int r = curr.first;
                int c = curr.second;

                for(int i=0;i<4;i++){
                    int nr = r + dx[i];
                    int nc = c + dy[i];

                    if(nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
                    if(visited[nr][nc]==1) continue;
                    if(grid[nr][nc]==1) return ans-1;
                    q.push({nr, nc});
                    visited[nr][nc]=1;  
                }
            }
        }
        return -1;
    }
};
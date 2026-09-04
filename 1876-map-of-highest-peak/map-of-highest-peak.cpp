class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();
        queue<pair<int, int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isWater[i][j]==1){
                    q.push({i, j});
                    isWater[i][j]=0;
                }
                else isWater[i][j] = INT_MAX;
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
                if(isWater[nr][nc] > isWater[r][c] + 1){
                        isWater[nr][nc] = isWater[r][c] + 1;
                        q.push({nr, nc});
                }
            }
        }
        return isWater;
    }
}; 
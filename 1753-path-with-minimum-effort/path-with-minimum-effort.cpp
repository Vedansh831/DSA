class Solution {
public:

    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> > pq; // Differnce , Row, Col
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        pq.push({0, {0, 0}});
        dist[0][0] = 0;

        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();

            int d = curr.first;
            int row = curr.second.first;
            int col = curr.second.second;
            if(row == n-1 && col == m-1) return d;
            for(int i=0;i<4;i++){
                int nr = row + dx[i];
                int nc = col + dy[i];

                if(nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
                int edge = abs(heights[row][col] - heights[nr][nc]);
                int newDist = max(d, edge);
                if(newDist < dist[nr][nc]){
                    dist[nr][nc] = newDist;
                    pq.push({newDist, {nr, nc}});
                }
            }
        }
        return 0;
    }
};
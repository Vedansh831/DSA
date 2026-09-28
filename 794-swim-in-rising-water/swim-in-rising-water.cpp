class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {

        int n = grid.size();

        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > pq;

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        dist[0][0] = grid[0][0];

        pq.push({grid[0][0], {0, 0}});
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            int t = curr.first;
            int row = curr.second.first;
            int col = curr.second.second;
            if (row == n - 1 && col == n - 1) return t;
            for (int i = 0; i < 4; i++) {
                int nr = row + dx[i];
                int nc = col + dy[i];
                if (nr < 0 || nc < 0 || nr >= n || nc >= n) continue;
                int newDist = max(t, grid[nr][nc]);
                if (newDist < dist[nr][nc]) {
                    dist[nr][nc] = newDist;
                    pq.push({newDist, {nr, nc}});
                }
            }
        }
        return -1;
    }
};
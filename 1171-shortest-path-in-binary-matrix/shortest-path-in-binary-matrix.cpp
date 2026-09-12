class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        // Start or destination is blocked
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
        int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};
        queue<pair<pair<int, int>, int>> q; // Row, Col, Dist
        vector<vector<int>> visited(n, vector<int>(n, 0));
        q.push({{0, 0}, 1});
        visited[0][0] = 1;
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            int row = curr.first.first;
            int col = curr.first.second;
            int dist = curr.second;
            if (row == n - 1 && col == n - 1) return dist;
            for (int i = 0; i < 8; i++) {
                int nr = row + dx[i];
                int nc = col + dy[i];
                if (nr < 0 || nc < 0 || nr >= n || nc >= n) continue;
                if (grid[nr][nc] == 1) continue;
                if (visited[nr][nc]) continue;
                visited[nr][nc] = 1;
                q.push({{nr, nc}, dist + 1});
            }
        }
        return -1;
    }
};
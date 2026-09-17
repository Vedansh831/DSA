class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        // Distance from a city to itself
        for (int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }
        // Build the distance matrix
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int wt = e[2];
            dist[u][v] = min(dist[u][v], wt);
            dist[v][u] = min(dist[v][u], wt);
        }
        // Floyd-Warshall Algorithm
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] != INT_MAX &&
                        dist[k][j] != INT_MAX) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        int ans = -1; int minCount = INT_MAX;
        // Count reachable cities for every city
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (dist[i][j] <= distanceThreshold) {
                    count++;
                }
            }
            // Use <= so that ties choose the largest city index
            if (count <= minCount) {
                minCount = count;
                ans = i;
            }
        }
        return ans;
    }
};
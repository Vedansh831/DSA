class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n + 1);
        for (auto it : times) {
            graph[it[0]].push_back({it[1], it[2]});
        }
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        // {distance, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > q;
        q.push({0, k});
        while (!q.empty()) {
            auto curr = q.top();
            q.pop();
            int distance = curr.first;
            int node = curr.second;
            // Skip outdated entries
            if (distance > dist[node]) continue; // This will avoid cycle if any
            for (auto neighbours : graph[node]) {
                int nextNode = neighbours.first;
                int d = neighbours.second;
                int newDist = distance + d;
                if (dist[nextNode] > newDist) {
                    dist[nextNode] = newDist;
                    q.push({newDist, nextNode});
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};
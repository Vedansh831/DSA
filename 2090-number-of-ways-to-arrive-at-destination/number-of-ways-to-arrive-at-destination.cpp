class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> graph(n);
        for (auto it : roads) {
            graph[it[0]].push_back({it[1], it[2]});
            graph[it[1]].push_back({it[0], it[2]});
        }
        // {distance, node}
        priority_queue< pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>> > pq; // Distance, Node
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        int mod = 1e9 + 7;
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            long long distance = curr.first;
            int node = curr.second;
            if (distance > dist[node]) continue;
            for (auto neighbours : graph[node]) {
                int nextNode = neighbours.first;
                int nodeWt = neighbours.second;
                long long newWt = distance + nodeWt;
                if (dist[nextNode] > newWt) {
                    dist[nextNode] = newWt;
                    pq.push({newWt, nextNode});
                    ways[nextNode] = ways[node];
                }
                else if (dist[nextNode] == newWt) {
                    ways[nextNode] = (ways[nextNode] + ways[node]) % mod;
                }
            }
        }
        return ways[n - 1] % mod;
    }
};
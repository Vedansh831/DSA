class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // This solution is based on weight sorting using priority queue , but we can also solve it using normal queue data structure 
        vector<pair<int, int>> graph[n];
        for (auto it : flights) {
            graph[it[0]].push_back({it[1], it[2]});
        }
        // {cost, {node, flights used}}
        priority_queue< pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> > pq;
        pq.push({0, {src, 0}});
        // dist[node][flights used]
        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));
        dist[src][0] = 0;
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            int wt = curr.first;
            int node = curr.second.first;
            int noK = curr.second.second;
            if (node == dst) return wt;
            if (noK == k + 1) continue;
            for (auto neighbours : graph[node]) {
                int no = neighbours.first;
                int w = neighbours.second;
                int newCost = wt + w;
                int newFlights = noK + 1;
                if (newCost < dist[no][newFlights]) {
                    dist[no][newFlights] = newCost;
                    pq.push({ newCost, {no, newFlights} });
                }
            }
        }
        return -1;
    }
};
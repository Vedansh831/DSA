class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<vector<pair<int, int>>> graph(n);

        for (auto it : flights) {
            graph[it[0]].push_back({it[1], it[2]});
        }

        queue<pair<int, pair<int, int>>> q; // flights , node, distance
        q.push({0, {src, 0}});
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        while(!q.empty()){
            auto curr = q.front();
            q.pop();

            int stops = curr.first;
            int node = curr.second.first;
            int d = curr.second.second;

            if(stops > k) continue;

            for(auto it : graph[node]){
                int nextNode = it.first;
                int distance = it.second;
                int newDist = distance + d;
                if(dist[nextNode] > newDist){
                    dist[nextNode] = newDist;
                    q.push({stops+1, {nextNode, newDist}});
                }
            }
        }

        if(dist[dst] == INT_MAX) return -1;
        return dist[dst];
    }
};
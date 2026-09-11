class Solution {
public:
    struct Edge{
        int src;
        int dest;
        int wt;
    };
    vector<list<pair<int, int>>> graph; // src -> dest, wt
    static bool cmp(Edge e1, Edge e2){
        return e1.wt < e2.wt;
    }
    int find(int x, vector<int>& parent){
        if(parent[x]==x) return x;
        return parent[x] = find(parent[x], parent);
    }
    void Union(int x, int y, vector<int>& parent, vector<int>& rank){
        x = find(x, parent);
        y = find(y, parent);

        if(rank[x] >= rank[y]){
            parent[y] = x;
            rank[x]++;
        }
        else{
            parent[x] = y;
            rank[y]++;
        }
    }
    int kruskals(vector<Edge> v, int n, int e){
        sort(v.begin(), v.end(), cmp);
        queue<pair<int, int>> q; // distance, node
        vector<int> parent(n);
        vector<int> rank(n, 0);
        for(int i=0;i<n;i++) parent[i] = i;

        int totalEdges = 0;
        int ans = 0;
        int i = 0; // Iterator over v
        while(totalEdges < n-1 && i < v.size()){
            Edge curr = v[i];
            int src = curr.src;
            int dest = curr.dest;
            int wt = curr.wt;
            int srcParent = find(src, parent);
            int destParent = find(dest, parent);
            if(srcParent != destParent){ // Not forming the cycle
                Union(src, dest, parent, rank);
                totalEdges++;
                ans += wt;
            }
            i++;
        }
        return ans;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        // Make the graph with each point is connected to every other node and them we can apply the kruskals or prims or dijstra to solve the problem, DSU used here
        int n = points.size();
        vector<Edge> v;
        int edges=0;
        // Making the graph;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                v.push_back({i, j, dist});
                edges++;
            }
        }
        int ans = kruskals(v, n, edges);
        return ans;
    }
};
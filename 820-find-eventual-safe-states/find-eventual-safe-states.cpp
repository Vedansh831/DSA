class Solution {
public:
    vector<list<int>> g;
    void add_edge(int src, int dest) {
        g[src].push_back(dest);
    }
    bool dfs(int node, unordered_set<int>& ele, unordered_set<int>& s) {
        // Already known to be safe
        if(ele.count(node)) return true;
        // Cycle detected
        if(s.count(node)) return false;
        s.insert(node);
        for(auto neighbour : g[node]) {
            if(!dfs(neighbour, ele, s)) {
                s.erase(node);
                return false;
            }
        }
        // Remove from current DFS path
        s.erase(node);
        // Node is safe
        ele.insert(node);
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        g.resize(n);
        // Construct graph
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < graph[i].size(); j++) {
                add_edge(i, graph[i][j]);
            }
        }
        unordered_set<int> ele;
        // Terminal nodes are safe
        for(int i = 0; i < n; i++) {
            if(graph[i].size() == 0) ele.insert(i);
        }
        // Check every node
        for(int i = 0; i < n; i++) {
            if(ele.count(i)) continue;
            unordered_set<int> visited;
            dfs(i, ele, visited);
        }
        vector<int> ans;
        for(auto e : ele) ans.push_back(e);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
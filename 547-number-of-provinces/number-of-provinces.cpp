static const auto fastIO = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<list<int>> graph;
    unordered_set<int> visited;
    void add_edge(int src, int dest, bool bi_dir = true){
        graph[src].push_back(dest);
        if(bi_dir == true){
            graph[dest].push_back(src); 
        }
    }
    void dfs(int node){
        visited.insert(node);
        for(auto nodes : graph[node]){
            if(visited.count(nodes)==0){
                dfs(nodes);
            }
        }
    }
    int connected_components(int v){
        int result = 0;
        for(int i=0;i<v;i++){
            if(visited.count(i)==0){
                result++;
                dfs(i);
            }
        }
        return result;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int v = isConnected[0].size();
        graph.resize(v);
        for(int i = 0; i < v; i++){
            for(int j = i + 1; j < v; j++){
                if(isConnected[i][j] == 1){
                    add_edge(i, j);
                }
            }
        }
        int ans = connected_components(v);
        return ans;
    }
};
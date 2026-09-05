class Solution {
public:

    vector<list<int>> graph;
    unordered_set<int> visited;
    void add_edge(int src, int dest){
        graph[src].push_back(dest);
    }
    void topoBFS(int V, vector<int>& ans){
        vector<int> inDegree(V, 0);
        for(int i=0;i<V;i++){
            for(auto neighbours : graph[i]) inDegree[neighbours]++;
        }
        queue<int> q;
        for(int i=0;i<V;i++){
            if(inDegree[i]==0){
                visited.insert(i);
                q.push(i);
            } 
        }
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            ans.push_back(curr);
            for(auto neighbours : graph[curr]){
                if(!visited.count(neighbours)){
                    inDegree[neighbours]--;
                    if(inDegree[neighbours]==0){
                        q.push(neighbours);
                        visited.insert(neighbours);
                    }
                }
            }
        }
        return;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        // int m = prerequisites[0].size();
        graph.resize(numCourses);
        for(int i=0;i<n;i++){
            add_edge(prerequisites[i][1], prerequisites[i][0]);
        }
        vector<int> ans;
        topoBFS(numCourses, ans);
        if(ans.size()!=numCourses) return {};
        return ans;
    }
};
class Solution {
public:
    vector<list<int>> graph;
    unordered_set<int> visited;
    void add_edge(int src, int dest){
        graph[src].push_back(dest);
    }
    void topoBFS(int V){
        vector<int> inDegree(V);
        for(int i=0;i<V;i++){
            for(auto neighbours : graph[i]){
                inDegree[neighbours]++;
            }
        }
        queue<int> q;
        for(int i=0;i<V;i++){
            if(inDegree[i]==0){
                q.push(i);
                visited.insert(i);
            }
        }
        while(!q.empty()){
            int curr = q.front();
            q.pop();

            for(auto neighbours : graph[curr]){
                inDegree[neighbours]--;
                if(inDegree[neighbours]==0){
                    q.push(neighbours);
                    visited.insert(neighbours);
                }
            }
        }
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph.resize(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            add_edge(prerequisites[i][1], prerequisites[i][0]);
        }
        topoBFS(numCourses);
        return visited.size()==numCourses;
    }
};
class Solution {
public:
    int find(int x, vector<int>& parent) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x], parent);
    }
    void unite(int a, int b, vector<int>& parent, vector<int>& rank) {
        a = find(a, parent);
        b = find(b, parent);
        if (a == b) return;
        if (rank[a] >= rank[b]) {
            parent[b] = a;
            rank[a]++;
        }
        else {
            parent[a] = b;
            rank[b]++;
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int> parent(20002);
        vector<int> rank(20002, 0);
        for (int i = 0; i < 20002; i++) parent[i] = i;
        unordered_set<int> nodes;
        for (auto &stone : stones) {
            int row = stone[0];
            int col = stone[1] + 10001;
            unite(row, col, parent, rank);
            nodes.insert(row);
            nodes.insert(col);
        }
        int components = 0;
        for (int node : nodes) {
            if (find(node, parent) == node) components++;
        }
        return n - components;
    }
};
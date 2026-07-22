class Solution {
public:
    void solve(vector<vector<int>>& ans, int n, int k, int idx, vector<int>& v) {
        if (v.size() == k) {
            ans.push_back(v);
            return;
        }

        for (int i = idx; i <= n; i++) {
            v.push_back(i);
            solve(ans, n, k, i + 1, v);
            v.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> v;
        solve(ans, n, k, 1, v);
        return ans;
    }
};
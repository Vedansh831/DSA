class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        // Store position of every number
        vector<pair<int, int>> pos(n * m + 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                pos[mat[i][j]] = {i, j};
            }
        }
        // Number of painted cells in each row and column
        vector<int> row(n, 0);
        vector<int> col(m, 0);
        for (int i = 0; i < arr.size(); i++) {
            int x = arr[i];
            int r = pos[x].first;
            int c = pos[x].second;
            row[r]++;
            col[c]++;
            // Entire row painted
            if (row[r] == m)
                return i;
            // Entire column painted
            if (col[c] == n)
                return i;
        }
        return -1;
    }
};
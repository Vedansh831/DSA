class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> ans(n, vector<int>(m));
        vector<int> r0(n);
        vector<int> r1(n);
        vector<int> c0(m);
        vector<int> c1(m);

        // Mark 0 and 1 in rows
        for(int i=0;i<n;i++){
            int one = 0;
            int zero = 0;
            for(int j=0;j<m;j++){
                if(grid[i][j]==0) zero++;
                else one++;
            }
            r0[i]=zero;
            r1[i]=one;
        }
        // Mark 0 and 1 in coloumns
        for(int i=0;i<m;i++){
            int one = 0;
            int zero = 0;
            for(int j=0;j<n;j++){
                if(grid[j][i]==0) zero++;
                else one++;
            }
            c0[i]=zero;
            c1[i]=one;
        }

        // Traverse and make up your required array
        for(int i=0;i<n;i++){
            int rowzero = r0[i];
            int rowone = r1[i];
            for(int j=0;j<m;j++){
                int colzero = c0[j];
                int colone = c1[j];
                int req = rowone + colone - rowzero - colzero;

                ans[i][j] = req;
            }
        }
        return ans;
    }
};
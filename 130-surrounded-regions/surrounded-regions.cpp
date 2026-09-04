class Solution {
public:

    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<int>>& ans){
        int n = board.size();
        int m = board[0].size();
        if(row < 0 || col < 0 || row >= n || col >= m) return;
        if(board[row][col]!='O' || ans[row][col]!=0) return;
        ans[row][col] = 1; // 1 means waha pe O aayega

        dfs(row+1, col, board, ans);
        dfs(row-1, col, board, ans);
        dfs(row, col+1, board, ans);
        dfs(row, col-1, board, ans);
        return;
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> ans(n, vector<int>(m, 0)); // 0 means not occupied
        // Top Side And Bottom Side
        for(int i=0;i<n;i++){
            dfs(i, 0, board, ans);
            dfs(i, m-1, board, ans);
        }
        // Left Side And Right Side
        for(int i=0;i<m;i++){
            dfs(0, i, board, ans);
            dfs(n-1, i, board, ans);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == 'O' && ans[i][j] == 0)board[i][j] = 'X';
            }
        }

        return;
    }
};
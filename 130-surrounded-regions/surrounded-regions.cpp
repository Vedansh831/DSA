class Solution {
public:
    vector<vector<int>> visited;
    void dfs(int i, int j, vector<vector<int>>& pos, vector<vector<char>>& v){
        if(i < 0 || j < 0 || i >= pos.size() || j >= pos[0].size()) return;
        if(visited[i][j]==1) return;
        visited[i][j]=1;
        if(v[i][j]=='O') pos[i][j]=2;
        else return;
        dfs(i+1, j, pos, v);
        dfs(i-1, j, pos, v);
        dfs(i, j+1, pos, v);
        dfs(i, j-1, pos, v);
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        visited.resize(n, vector<int>(m, 0));
        vector<vector<int>> pos(n, vector<int>(m, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='X') pos[i][j]=1;
                else pos[i][j]=0;
            }
        }
        for(int i=0;i<n;i++){
            if(pos[i][0]==0) dfs(i, 0, pos, board);
            if(pos[i][m-1]==0) dfs(i, m-1, pos, board);
        }
        for(int j=0;j<m;j++){
            if(pos[0][j]==0) dfs(0, j, pos, board);
            if(pos[n-1][j]==0) dfs(n-1, j, pos, board);
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pos[i][j]!=2) board[i][j]='X';
            }
        }
        return;
    }
};
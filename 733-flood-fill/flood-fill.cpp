class Solution {
public:
    void dfs(int row, int col, int color, int prevColor, vector<vector<int>>& image){
        int n = image.size();
        int m = image[0].size();
        if(row < 0 || col < 0 || row >= n || col >= m) return;
        if(image[row][col]!=prevColor) return;
        image[row][col] = color;

        dfs(row+1, col, color, prevColor, image);
        dfs(row-1, col, color, prevColor, image);
        dfs(row, col+1, color, prevColor, image);
        dfs(row, col-1, color, prevColor, image);
        return;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        if(image[sr][sc] == color) return image;
        dfs(sr, sc, color, image[sr][sc], image);
        return image;
    }
};
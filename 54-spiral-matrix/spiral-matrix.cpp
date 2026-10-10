class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int minr=0;
        int minc=0;
        int maxr=n-1;
        int maxc=m-1;
        
        vector<int> ans;
        while(minr<=maxr && minc<=maxc){
       for (int i = minc; i <= maxc; i++)
        {
           ans.push_back(matrix[minr][i]);
        }
        minr++;
        if(minr>maxr || minc>maxc) break;
        //down
        for (int i = minr; i <= maxr; i++)
        {
          ans.push_back(matrix[i][maxc]);
        }
        maxc--;
         if(minr>maxr || minc>maxc) break;
        //left
        for (int i = maxc; i >= minc; i--)
        {
            ans.push_back(matrix[maxr][i]);
        }
        maxr--;
         if(minr>maxr || minc>maxc) break;
        //up
        for (int i = maxr; i >= minr; i--)
        {
           ans.push_back(matrix[i][minc]);
        }
        minc++;
        }
        return ans;
    }
};
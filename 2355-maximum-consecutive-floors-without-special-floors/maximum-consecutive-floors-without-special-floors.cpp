class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        int n = special.size();
        sort(special.begin(), special.end());
        int ans = special[0]-bottom;
        for(int i=1;i<n;i++){
            int diff = special[i]-special[i-1]-1;
            if(diff > ans) ans = diff;
        }
        int last = top-special[n-1];
        if(last > ans) ans = last;
        return ans;
    }
};
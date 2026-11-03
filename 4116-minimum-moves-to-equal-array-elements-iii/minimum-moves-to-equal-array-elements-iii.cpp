class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long ans = 0;
        int n = nums.size();
        for(int i=0;i<n-1;i++){
            ans += nums[n-1]-nums[i];
        }
        return ans;
    }
};
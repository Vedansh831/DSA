class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int fidx;
        int sidx;

        int mx=INT_MIN;
        int mn=INT_MAX;

        for(int i=0;i<n;i++){
            if(nums[i] > mx){
                mx = nums[i];
                fidx = i;
            }
            if(nums[i] < mn){
                mn = nums[i];
                sidx = i;
            }
        }
        // Both deleted from front
        int a = max(fidx, sidx) + 1;

        // Both deleted from back
        int b = max(n - fidx, n - sidx);

        // One from front and one from back
        int c = min(fidx, sidx) + 1 + n - max(fidx, sidx);

        return min({a, b, c});
    }
};
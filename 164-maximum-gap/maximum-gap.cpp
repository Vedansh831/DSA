class Solution {
public:

    void Radix(vector<int>& nums, long long exp){
        int n = nums.size();
        vector<int> output(n);
        int count[10] = {0};
        // Take the frequency of the exp place element
        for(int i=0;i<n;i++){
            int digit = (nums[i]/exp)%10;
            count[digit]++;
        }
        // Convert count into prefix sum
        for(int i=1;i<10;i++){
            count[i] = count[i] + count[i-1];
        }
        // Build the output array ( Traverse from left to right for stability)
        for(int i=n-1;i>=0;i--){
            int digit = (nums[i]/exp)%10;
            output[count[digit]-1] = nums[i];
            count[digit]--;
        }
        nums = output;
    }

    void radixSort(vector<int>& nums){
        int mx = *max_element(nums.begin(), nums.end());
        for(long long exp=1;mx/exp>0;exp*=10){
            Radix(nums, exp);
        }
    }

    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        radixSort(nums);
        int ans = 0;
        for(int i=1;i<nums.size();i++){
            int diff = nums[i] - nums[i-1];
            if(diff>ans) ans = diff;
        }
        return ans;
    }
};
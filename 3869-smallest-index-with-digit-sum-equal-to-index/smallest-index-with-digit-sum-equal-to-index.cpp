class Solution {
public:
    int sum(int n){
        int s = 0;
        while( n > 0){
            int last = n%10;
            s += last;
            n /= 10;
        }
        return s;
    }
    int smallestIndex(vector<int>& nums) {
        int ans = -1;
        for(int i=0;i<nums.size();i++){
            if(sum(nums[i]) == i){
                ans = i;
                break;
            }
        }
        return ans;
    }
};
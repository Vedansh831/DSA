class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int sum;
        int csum = INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            int lo = i+1;
            int hi = n-1;
            while(lo<hi){
                if(target==nums[i]+nums[lo]+nums[hi]){
                    sum = nums[i]+nums[lo]+nums[hi];
                    break;
                }
                else if(nums[i]+nums[lo]+nums[hi]<target){
                    int s = abs(target-nums[i]-nums[lo]-nums[hi]);
                    if(csum>s){ // Matlab difference kam hai ab sum ko update kardo
                        csum=s;
                        sum = nums[i]+nums[lo]+nums[hi];
                    }
                    lo++;
                }
                else{
                    int s = abs(target-nums[i]-nums[lo]-nums[hi]);
                        if(csum>s){ // Matlab difference kam hai ab sum ko update kardo
                        csum=s;
                        sum = nums[i]+nums[lo]+nums[hi];
                    }
                    hi--;
                }
            }
        }
        return sum;
    }
};
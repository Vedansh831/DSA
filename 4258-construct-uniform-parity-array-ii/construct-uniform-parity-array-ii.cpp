class Solution {
public:

    bool check(vector<int>& nums, int target){
        int n = nums.size();

        int minOdd = INT_MAX;
        int minEven = INT_MAX;

        for(int i=0;i<n;i++){
            if(nums[i]%2==0) minEven = min(nums[i], minEven);
            else minOdd = min(nums[i], minOdd);
        }

        for(int x : nums){
            if(x % 2 == target) continue; // if target == 1 odd if target == 0 even

            // Need x - y to have target parity
            if (target == 1) {
                // Need opposite parity y
                if (x % 2 == 0) {
                    if (minOdd >= x)
                        return false;
                } else {
                    if (minEven >= x)
                        return false;
                }
            } 
            else {
                // Need same parity y
                if (x % 2 == 0) {
                    if (minEven >= x)
                        return false;
                } else {
                    if (minOdd >= x)
                        return false;
                }
            }
        }

        return true;
    }

    bool uniformArray(vector<int>& nums1) {
        return check(nums1, 1) || check(nums1, 0);
    }
};
class Solution {
public:
 vector<int> searchRange(vector<int>& nums, int target) {
        
        int first = findFirst(nums, target);
        int last = findLast(nums, target);
        return{ first, last};
    }

     int findFirst(vector<int>& nums, int target){
        int n = nums.size();
        int start = 0;
        int end = n-1;
        int mid = end + (start-end)/2;
        int ans = -1;

        while(start<=end){
             int mid = end + (start-end)/2;
            if(nums[mid]==target){
                ans = mid;
                end = mid-1;
            }
            else if(nums[mid]< target){
                start = mid + 1;
            }
            else{
                end = mid -1;
            }
        }
        return ans;
    }

     int findLast(vector<int>& nums, int target){
        int n = nums.size();
        int start = 0;
        int end = n-1;
        int mid = end + (start-end)/2;
        int ans = -1;

        while(start<=end){
             int mid = end + (start-end)/2;
            if(nums[mid]==target){
                ans = mid;
                start = mid + 1;
            }
            else if(nums[mid]< target){
                start = mid + 1;
            }
            else{
                end = mid -1;
            }
        }
        return ans;
    }
};
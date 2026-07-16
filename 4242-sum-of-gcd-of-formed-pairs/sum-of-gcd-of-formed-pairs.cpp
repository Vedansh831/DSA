class Solution {
public:

    int gcd(int a, int b){
        while(b){
            a %= b;
            swap(a, b);
        }
        return a;
    }

    long long gcdSum(vector<int>& nums) {
        int mx=INT_MIN;
        vector<int> v(nums.size());
        for(int i=0;i<nums.size();i++){
            if(mx<nums[i]) mx = nums[i];
            int a = gcd(nums[i], mx);
            v[i]=a;
        }
        sort(v.begin(), v.end());
        long long ans = 0;
        int i=0;
        int j=v.size()-1;
        while(i<j){
            int a = v[i];
            int b = v[j];
            int GCD = gcd(a, b);
            ans += GCD;
            i++;
            j--;
        }

        return ans;
    }
};
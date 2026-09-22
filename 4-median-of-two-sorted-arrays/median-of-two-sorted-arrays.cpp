class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> res(m + n);
        int i = 0;
        int j = 0;
        int k = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] <= nums2[j])
                res[k++] = nums1[i++]; //<= to make stable sort algorithm
            else
                res[k++] = nums2[j++];
        }
        if (i == nums1.size()) {
            while (j < nums2.size())
                res[k++] = nums2[j++];
        }
        if (j == nums2.size()) {
            while (i < nums1.size())
                res[k++] = nums1[i++];
        }
        int a = res.size();
        if (res.size() % 2 != 0)
            return (double)res[a / 2];
        else {
            int n1 = a / 2;
            int n2 = (a / 2 - 1);
            float ans = (res[n1] + res[n2]) / 2.0;
            return ans;
        }
    }
};
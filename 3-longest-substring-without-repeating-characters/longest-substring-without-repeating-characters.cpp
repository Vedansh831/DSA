class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // int n = s.size();
        // int max = INT_MIN;
        // if(n==0) return 0;
        // if(n==1) return 1;
        // for(int i=0;i<n-1;i++){
        //     int count = 0 ;
        //     vector<int> v(150,0);
        //     for(int j=i;j<n;j++){
        //         int idx = (int)s[j];
        //         if(v[idx]==0) v[idx]=1;
        //         else break;
        //         count++;
        //     }
        //     if(count>max) max = count;
        // }
        // return max;
         vector<int> lastIndex(256, -1); // store last seen index for each char
    int maxLen = 0;
    int start = 0; // start index of current window

    for (int i = 0; i < s.size(); i++) {
        // If character was seen after or at start, move start
        if (lastIndex[s[i]] >= start) {
            start = lastIndex[s[i]] + 1;
        }
        lastIndex[s[i]] = i; // update last seen index

        maxLen = max(maxLen, i - start + 1); // update max length
    }
    return maxLen;
    }
};
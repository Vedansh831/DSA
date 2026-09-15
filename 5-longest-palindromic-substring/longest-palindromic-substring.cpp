class Solution {
public:
    int f(string& s, int left, int right){
        while(left>=0 && right<s.size() && s[left]==s[right]){
            left--;
            right++;
        }
        return right - left - 1 ;
    }
    string longestPalindrome(string s) {
        int start = 0;
        int end = 0;
        for(int i=0;i<s.size();i++){
            int len = f(s, i, i); // odd
            int len2 = f(s, i, i+1); // even
            int l = max(len,len2);
            if(l > end - start){
                start = i - (l-1)/2;
                end = i + l/2;
            }
        }
        return s.substr(start, end-start+1);
    }
};
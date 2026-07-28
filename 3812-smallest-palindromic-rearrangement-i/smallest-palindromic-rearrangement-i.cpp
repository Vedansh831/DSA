class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        if (n == 1) return s;
        vector<int> freq(256, 0);
        for (char c : s) freq[c]++;
        string left = "";
        for (int i = 0; i < 256; i++) {
            while (freq[i] >= 2) {
                left += char(i);
                freq[i] -= 2;
            }
        }
        char mid = '0';
        for (int i = 0; i < 256; i++) {
            if (freq[i]) {
                mid = char(i);
                break;
            }
        }
        string right = left;
        reverse(right.begin(), right.end());
        if (mid != '0') return left + mid + right;
        else return left + right;
    }
};
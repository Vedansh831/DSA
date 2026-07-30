class Solution {
public:
    const long long LIM = 1000001;
    // nCr with value capped at LIM
    long long C(int n, int r) {
        if (r > n) return 0;
        r = min(r, n - r);
        long long ans = 1;
        for (int i = 1; i <= r; i++) {
            ans = ans * (n - r + i) / i;
            if (ans >= LIM) return LIM;
        }
        return ans;
    }
    // Count distinct permutations
    long long ways(vector<int>& cnt) {
        int rem = 0;
        for (int x : cnt) rem += x;
        long long ans = 1;
        int left = rem;
        for (int x : cnt) {
            if (x == 0) continue;
            ans *= C(left, x);
            if (ans >= LIM) return LIM;
            left -= x;
        }
        return ans;
    }
    string smallestPalindrome(string s, int k) {
        vector<int> freq(26);
        for (char c : s) freq[c - 'a']++;
        vector<int> half(26);
        char mid = 0;
        int m = 0;
        for (int i = 0; i < 26; i++) {
            half[i] = freq[i] / 2;
            m += half[i];

            if (freq[i] & 1)
                mid = char('a' + i);
        }
        if (ways(half) < k) return "";
        string left = "";
        for (int pos = 0; pos < m; pos++) {
            for (int c = 0; c < 26; c++) {
                if (half[c] == 0) continue;
                half[c]--;
                long long cnt = ways(half);
                if (cnt >= k) {
                    left.push_back(char('a' + c));
                    break;
                }
                k -= cnt;
                half[c]++;
            }
        }
        string right = left;
        reverse(right.begin(), right.end());
        if (mid) return left + string(1, mid) + right;
        return left + right;
    }
};
class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.size();
        const long long MOD = 1e9 + 7;
        vector<long long> dp(n + 1, 0);
        vector<int> last(26, -1);
        dp[0] = 1; // empty subsequence
        for(int i = 0; i < n; i++) {
            dp[i + 1] = (2 * dp[i]) % MOD;
            if(last[s[i] - 'a'] != -1) {
                int j = last[s[i] - 'a'];
                dp[i + 1] = (dp[i + 1] - dp[j] + MOD) % MOD;
            }
            last[s[i] - 'a'] = i;
        }
        return (dp[n] - 1 + MOD) % MOD;
    }
};
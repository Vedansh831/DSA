class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();
        vector<int> freq(26, 0);
        // Count character frequencies in s
        for (char c : s)  freq[c - 'a']++;
        // Find the longest prefix we can match exactly
        int match_len = 0;
        for (int i = 0; i < n; ++i) {
            if (freq[target[i] - 'a'] > 0) {
                match_len++;
                freq[target[i] - 'a']--;
            } else {
                break;
            }
        }
        // We cannot exactly match the whole string. 
        // Backtrack on the last character if we did.
        int i = min(n - 1, match_len);
        if (match_len == n) {
            freq[target[n - 1] - 'a']++;
            i = n - 1;
        }
        // Backtrack to find the branching point
        while (i >= 0) {
            // Find the smallest available char strictly greater than target[i]
            int best_char_idx = -1;
            for (int c = (target[i] - 'a') + 1; c < 26; ++c) {
                if (freq[c] > 0) {
                    best_char_idx = c;
                    break; 
                }
            }
            if (best_char_idx != -1) {
                freq[best_char_idx]--; 
                // Build the result
                string res = target.substr(0, i);
                res.push_back((char)(best_char_idx + 'a'));
                // Append remaining characters (naturally sorted)
                for (int c = 0; c < 26; ++c) {
                    while (freq[c] > 0) {
                        res.push_back((char)(c + 'a'));
                        freq[c]--;
                    }
                }   
                return res;
            }   
            // Backtrack if no valid character was found
            i--;
            if (i >= 0) {
                freq[target[i] - 'a']++;
            }
        }
        // If no valid permutation is possible
        return "";
    }
};
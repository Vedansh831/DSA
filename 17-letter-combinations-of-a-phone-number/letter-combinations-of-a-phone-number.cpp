class Solution {
public:
    unordered_map<char, string> mp;
    vector<string> ans;
    void solve(string &digits, int idx, string &curr) {
        if (idx == digits.size()) {
            ans.push_back(curr);
            return;
        }
        // Get letters corresponding to current digit
        string letters = mp[digits[idx]];
        // Try each letter
        for (char ch : letters) {
            curr.push_back(ch);           // Choose
            solve(digits, idx + 1, curr); // Explore
            curr.pop_back();              // Backtrack
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        string curr = "";
        solve(digits, 0, curr);
        return ans;
    }
};
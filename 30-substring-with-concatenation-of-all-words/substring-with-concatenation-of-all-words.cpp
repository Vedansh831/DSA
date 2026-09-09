class Solution {
public:
    // Optimal Code
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> need;
        for (auto &word : words) need[word]++;
        int len = words[0].size();
        int total = words.size();
        vector<int> ans;
        // Try every possible alignment
        for (int offset = 0; offset < len; offset++) {
            int left = offset;
            int count = 0;
            unordered_map<string, int> have;
            for (int right = offset; right + len <= s.size(); right += len) {
                string word = s.substr(right, len);
                // Word is not required
                if (!need.count(word)) {
                    have.clear();
                    count = 0;
                    left = right + len;
                    continue;
                }
                have[word]++;
                count++;
                // Too many copies of this word
                while (have[word] > need[word]) {
                    string remove = s.substr(left, len);
                    have[remove]--;
                    left += len;
                    count--;
                }
                // Exactly all words are present
                if (count == total) {
                    ans.push_back(left);
                    // Move left forward for next possible window
                    string remove = s.substr(left, len);
                    have[remove]--;
                    left += len;
                    count--;
                }
            }
        }
        
        return ans;
    }
};
class Solution {
public:
    bool isValid(string s) {
        int count = 0;
        for (char c : s) {
            if (c == '(') {
                count++;
            }
            else if (c == ')') {
                count--;
                if (count < 0)
                    return false;
            }
        }
        return count == 0;
    }
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        unordered_set<string> visited;
        queue<string> q;
        q.push(s);
        visited.insert(s);
        bool found = false;
        while (!q.empty()) {
            int size = q.size();
            // Process all strings having the same number
            // of removals.
            while (size--) {
                string curr = q.front();
                q.pop();
                if (isValid(curr)) {
                    ans.push_back(curr);
                    found = true;
                }
                // If we already found valid strings at this
                // level, don't generate strings with more removals.
                if (found) continue;
                for (int i = 0; i < curr.size(); i++) {
                    // Only remove parentheses.
                    if (curr[i] != '(' && curr[i] != ')') continue;
                    string next = curr.substr(0, i) + curr.substr(i + 1);
                    if (visited.find(next) == visited.end()) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }
            // We found valid strings using the minimum
            // number of removals.
            if (found)
                break;
        }
        return ans;
    }
};
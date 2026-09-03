class Solution {
public:
    vector<vector<int>> count;
    bool compare(char a, char b) {
        int n = count[0].size();
        // Compare position by position
        for (int pos = 0; pos < n; pos++) {
            if (count[a - 'A'][pos] != count[b - 'A'][pos]) {
                return count[a - 'A'][pos] > count[b - 'A'][pos];
            }
        }
        // If completely tied, alphabetical order
        return a < b;
    }
    string rankTeams(vector<string>& votes) {
        int n = votes[0].size();
        // count[team][position]
        count.resize(26, vector<int>(n, 0));
        // Count every team's position
        for (string vote : votes) {
            for (int pos = 0; pos < n; pos++) {
                count[vote[pos] - 'A'][pos]++;
            }
        }
        string teams = votes[0];
        // Sort using our comparator
        sort(teams.begin(), teams.end(),  [this](char a, char b) { return compare(a, b); });
        return teams;
    }
};
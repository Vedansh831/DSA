class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        // Count frequency of each task
        for(char task : tasks) {
            freq[task - 'A']++;
        }
        // Find maximum frequency
        int maxFreq = 0;
        for(int f : freq) {
            maxFreq = max(maxFreq, f);
        }
        // Count how many tasks have maximum frequency
        int countMax = 0;
        for(int f : freq) {
            if(f == maxFreq) {
                countMax++;
            }
        }
        // Minimum intervals required
        int ans = (maxFreq - 1) * (n + 1) + countMax;
        // We can never have fewer intervals than total tasks
        return max((int)tasks.size(), ans);
    }
};
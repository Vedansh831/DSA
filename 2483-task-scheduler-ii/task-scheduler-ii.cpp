class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<int, long long> lastDay;
        long long day = 0;
        for(int task : tasks) { 
            // Move to the next day
            day++;
            // If task was done before
            if(lastDay.count(task)) {  
                long long requiredDay = lastDay[task] + space + 1;
                // Need to take breaks
                if(day < requiredDay) {
                    day = requiredDay;
                }
            }
            // Update the last day this task was completed
            lastDay[task] = day;
        }
        
        return day;
    }
};
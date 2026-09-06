class Solution {
public:

    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> s(deadends.begin(), deadends.end()); // This will check for deadends
        if(s.find("0000")!=s.end()) return -1;
        queue<pair<string, int>> q;
        unordered_set<string> visited;
        q.push({"0000", 0});

        while(!q.empty()){
            string code = q.front().first;
            int steps = q.front().second;
            q.pop();

            if(code == target) return steps;

            for(int i=0;i<4;i++){
                char original = code[i]; // original ke ek upar ya ek neche
                if(code[i]=='9') code[i] = '0'; // Incrementing
                else code[i]++; 

                if (!s.count(code) && !visited.count(code)) {
                    visited.insert(code);
                    q.push({code, steps + 1});
                }

                code[i] = original;

                if(code[i]=='0') code[i] = '9';
                else code[i]--; // Decrementing

                if(!s.count(code) && !visited.count(code)){
                    visited.insert(code);
                    q.push({code, steps+1});
                } 

                code[i] = original;
            }
        }

        return -1;
    }
};
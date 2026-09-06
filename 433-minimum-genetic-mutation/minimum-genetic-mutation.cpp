class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        queue<pair<string, int>> q;
        unordered_set<string> s(bank.begin(), bank.end());
        int steps = 0;
        q.push({startGene, 0});
        s.erase(startGene);
        vector<char> seq = {'A', 'G', 'C', 'T'};

        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            if(word == endGene) return steps;
            for(int i=0;i<word.size();i++){
                char original = word[i];
                for(auto ch : seq){
                    word[i] = ch;
                    if(s.find(word) != s.end()){
                        q.push({word, steps+1});
                        s.erase(word);
                    }
                }
                word[i] = original;
            }
        }
        return -1;
    }
};
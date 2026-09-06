class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        unordered_set<string> s;
        for(int i=0;i<wordList.size();i++){
            s.insert(wordList[i]);
        }
        q.push({beginWord, 1});
        s.erase(beginWord);

        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            if(word == endWord) return steps;
            q.pop();

            for(int i=0;i<word.size();i++){
                char original = word[i];
                for(char ch = 'a' ; ch <= 'z'; ch++){
                    word[i] = ch;
                    if(s.find(word)!=s.end()){
                        s.erase(word);
                        q.push({word, steps+1});
                    }
                }
                word[i] = original; // Because we can change at every index so check for all
            } 
        }
        return 0;
    }
};
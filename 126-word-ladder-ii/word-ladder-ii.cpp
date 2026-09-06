class Solution {
public:
    unordered_map<string, int> m; // This will store the string and its occurance level
    vector<vector<string>> ans;
    string b;
    void dfs(string s, vector<string>& v){
        if(s == b){
            reverse(v.begin(), v.end());
            ans.push_back(v);
            reverse(v.begin(), v.end());
            return;
        }
        int steps = m[s]; // Last wale element string ki steps hai
        // Backtracking through the map
        for(int i=0;i<s.size();i++){
            char original = s[i];
            for(char ch = 'a' ; ch <= 'z' ; ch++){
                s[i] = ch;
                if(m.find(s)!=m.end() && m[s] + 1 == steps){ // Mil gya and steps 1 kam hai tab hi lena hai answer mein
                    v.push_back(s);
                    dfs(s, v);
                    v.pop_back();
                }
            }
            s[i] = original;
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        b = beginWord;
        q.push(beginWord);
        m[beginWord] = 1;
        unordered_set<string> s(wordList.begin(), wordList.end());
        s.erase(beginWord);
        while(!q.empty()){
            string word = q.front();
            int steps = m[word];
            q.pop();
            if(word == endWord) break;
            for(int i=0;i<word.size();i++){
                char original = word[i];
                for(char ch = 'a' ; ch <= 'z' ; ch++){
                    word[i] = ch;
                    if(s.count(word)){
                        q.push(word);
                        m[word] = steps + 1;
                        s.erase(word);
                    }
                }
                word[i] = original;
            }
        }
        if(m.find(endWord)!=m.end()){
            vector<string> v;
            v.push_back(endWord);
            dfs(endWord, v);
        }
        return ans;
    }
};
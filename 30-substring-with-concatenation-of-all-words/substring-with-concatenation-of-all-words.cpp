class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> m;
        for(auto s : words) m[s]++;
        int n = words[0].size();
        int strs = s.size();
        vector<int> ans;
        int wSz = n * words.size(); // Window Size
        for( int i=0 ; i<=strs - wSz ; i++ ){
            unordered_map<string, int> check;
            for(int j=i;j<i+wSz;){ // Putting all the strings in the new map
                string st = "";
                for(int k=0;k<n;k++){
                    st += s[j++];
                }
                check[st]++;
            }
            if(m == check) ans.push_back(i);
            check.clear();
        }
        return ans;
    }
};
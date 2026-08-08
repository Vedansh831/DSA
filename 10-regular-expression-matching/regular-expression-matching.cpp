class Solution {
public:
    bool f(string& s, string& p, int i, int j){
        if(j == p.size()) return i == s.size();
        if(i == s.size()){
            if(j+1 < p.size() && p[j+1]=='*') 
                return f(s, p, i, j+2);
                return false;
        }
        if(j+1 < p.size() && p[j+1]=='*'){
            if(f(s, p, i, j+2)) return true; // skip
            if(s[i]==p[j] || p[j]=='.')
                if(f(s, p, i+1, j)) return true; // take
        }

        if(s[i]==p[j] || p[j]=='.') 
            return f(s, p, i+1, j+1);

        return false;
    }
    bool isMatch(string s, string p) {
        return f(s, p, 0 , 0);
    }
};
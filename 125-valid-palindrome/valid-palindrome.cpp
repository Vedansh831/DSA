class Solution {
public:
    string reverse(string s){
        int i=0;
        int j=s.size()-1;
        while(i<j){
            swap(s[i], s[j]);
            i++;
            j--;
        }
        return s;
    }
    bool isPalindrome(string s) {
        string str = "";
        for(int i=0;i<s.size();i++){
            if(s[i]>='A' && s[i]<='Z') s[i] = s[i] + 32;
            if((s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')) str+=s[i];
        }
        string strr = reverse(str);
        return (str==strr);
    }
};
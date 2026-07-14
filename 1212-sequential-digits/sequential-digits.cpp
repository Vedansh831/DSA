class Solution {
public:
    // First on github pushed
    void generate(int low, int high, int num, string s, vector<int>& ans){
        if(num>9) return;
        string next = to_string(num);
        s = s + next;
        int n = stoi(s);
        if(n>=low && n<=high){
            ans.push_back(n);
        }
        if(n>high) return;
        generate(low, high, num+1, s, ans);
        return;
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for(int i=1;i<=9;i++){
            generate(low, high, i, "", ans);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
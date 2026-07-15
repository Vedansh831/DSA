class Solution {
public:
    bool isNumber(string s) {
        int n = s.size();
        int decicount = 0;
        int digitcount = 0;
        int ecount = 0;
        bool digitAfterE = true;
        if (s[0] == '.' && n == 1) return false;
        for (int i = 0; i < n; i++) {
            if (isdigit(s[i])) {
                digitcount++;
                if (ecount) digitAfterE = true;
                continue;
            }
            if ((s[i] == 'e' || s[i] == 'E')) {
                if (digitcount == 0) return false;      // no digit before e
                if (ecount == 1) return false;          // multiple e's
                if (i == n - 1 || i == 0) return false; // e at beginning/end
                ecount++;
                digitAfterE = false;
                continue;
            }
            if (s[i] == '-' || s[i] == '+') {
                if (i != 0) {
                    if (s[i - 1] != 'e' && s[i - 1] != 'E')
                        return false;
                }
                continue;
            }
            if (s[i] == '.') {
                if (decicount == 1) return false;   // multiple dots
                if (ecount == 1) return false;      // dot after e
                decicount++;
                continue;
            }
            return false; // invalid character
        }
        if (digitcount == 0) return false;
        if (ecount && !digitAfterE) return false;
        return true;
    }
};
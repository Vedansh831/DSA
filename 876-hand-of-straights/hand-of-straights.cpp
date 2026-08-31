class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;
        map<int, int> mp;
        for (auto ele : hand) mp[ele]++;
        while (!mp.empty()) {
            int x = mp.begin()->first;
            int k = groupSize;
            while (k > 0) {
                if (mp.count(x)) {
                    mp[x]--;
                    if (mp[x] == 0) mp.erase(x);
                    x++;
                    k--;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
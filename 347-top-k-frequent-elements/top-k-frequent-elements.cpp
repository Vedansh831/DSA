class Solution {
public:
    typedef pair<int,int> pi;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m; // map pair is element , frequency
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        priority_queue<pi, vector<pi>, greater<pi>> pq; // priority queue pair is frequency , element
        for(auto x : m){
            int element = x.first;
            int frequency = x.second;
            pair<int,int> p = {frequency,element};
            pq.push(p);
            // pq.push({x.second,x.first});
            if(pq.size()>k) pq.pop();
        }
        vector<int> ans;
        while(pq.size()>0){
            int ele = pq.top().second;
            ans.push_back(ele);
            pq.pop();
        }
        return ans;
    }
};
class Solution {
public:
    typedef pair<int, vector<int>> pi;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pi> pq; // distance squared , points
        for(vector<int> v : points){
            int x = v[0];
            int y = v[1];
            int distance = x*x + y*y;
            pq.push({distance,v});
            if(pq.size()>k) pq.pop();
        }
        while(pq.size()>0){
            vector<int> v = pq.top().second;
            ans.push_back(v);
            pq.pop();
        }
        return ans;
    }
};
class Twitter {
public:
    unordered_map<int, unordered_set<int>> mp; // follower -> followees
    unordered_map<int, vector<pair<int, int>>> tweets; // user -> {timestamp, tweetId}
    int time = 0;
    Twitter() {
    }
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }
    vector<int> getNewsFeed(int userId) {
        // {timestamp, tweetId}
        priority_queue<pair<int, int>> pq;
        // User's own tweets
        for (auto tweet : tweets[userId]) {
            pq.push(tweet);
        }
        // Tweets of people user follows
        for (int followee : mp[userId]) {
            for (auto tweet : tweets[followee]) {
                pq.push(tweet);
            }
        }
        vector<int> ans;
        // Get 10 most recent tweets
        while (!pq.empty() && ans.size() < 10) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId)
            return;
        mp[followerId].insert(followeeId);
    }
    void unfollow(int followerId, int followeeId) {
        mp[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
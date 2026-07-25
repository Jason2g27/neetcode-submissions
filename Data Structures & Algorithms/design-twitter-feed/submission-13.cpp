class Twitter {
public:
    int time;
    unordered_map<int, unordered_set<int>> users;
    unordered_map<int, vector<pair<int, int>>> tweets;
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> feed;
        users[userId].insert(userId);
        for(auto& user : users[userId]){
            int n = tweets[user].size();
            int i = n - 1;
            while (i >= 0 && i >= n - 10) {
                feed.push(tweets[user][i]);
                i--;
            }
        }
        vector<int> result;
        while (!feed.empty() && result.size() < 10) {
            result.push_back(feed.top().second);
            feed.pop();
        }
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        users[followerId].insert(followeeId); 
    }
    
    void unfollow(int followerId, int followeeId) {
        users[followerId].erase(followeeId);
    }
};

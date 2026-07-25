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
    // Stores: {timestamp, tweetId, userId, index_in_user_tweets}
    priority_queue<vector<int>> maxHeap;
    
    users[userId].insert(userId);
    
    // Step 1: Push only the single newest tweet for each user
    for (int followeeId : users[userId]) {
        int n = tweets[followeeId].size();
        if (n > 0) {
            auto& latest = tweets[followeeId][n - 1];
            // Format: {timestamp, tweetId, followeeId, index}
            maxHeap.push({latest.first, latest.second, followeeId, n - 1});
        }
    }
    
    vector<int> result;
    
    // Step 2: Extract top 10 elements lazily
    while (!maxHeap.empty() && result.size() < 10) {
        auto top = maxHeap.top();
        maxHeap.pop();
        
        result.push_back(top[1]); // Append tweetId
        
        int followeeId = top[2];
        int idx = top[3];
        
        // Push the previous tweet from the SAME user if it exists
        if (idx - 1 >= 0) {
            auto& prev = tweets[followeeId][idx - 1];
            maxHeap.push({prev.first, prev.second, followeeId, idx - 1});
        }
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

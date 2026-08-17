class Twitter {
   public:
    vector<int> tweets;
    int timer = 0;
    unordered_map<int, vector<pair<int, int>>> user_tweets;
    unordered_map<int, vector<int>> following;
    Twitter() {}

    void postTweet(int userId, int tweetId) {
        timer++;
        user_tweets[userId].push_back({tweetId, timer});
        return;
    }

    vector<int> getNewsFeed(int userId) {
        vector<pair<int, int>> result;
        vector<pair<int, int>> ownTweets = user_tweets[userId];
        vector<pair<int, int>> followingTweets;
        for (auto el : following[userId]) {
            for (auto it : user_tweets[el]) {
                result.push_back(it);
            }
        }
        for (auto el : ownTweets) result.push_back(el);
        sort(result.begin(), result.end(),
             [](pair<int, int> i, pair<int, int> j) { return i.second > j.second; });

        int siz = 10;
        if (result.size() < 10) siz = result.size();
        vector<int> ans = vector<int>(siz);
        for (int i = 0; i < siz; i++) {
            ans[i] = result[i].first;
        }
        return ans;
    }

    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;

        // Avoid duplicate follow
        for (auto id : following[followerId]) {
            if (id == followeeId) return;
        }

        following[followerId].push_back(followeeId);
        return;
    }

    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        int ind;
        bool present = false;
        for (int i = 0; i < following[followerId].size(); i++) {
            if (following[followerId][i] == followeeId) {
                ind = i;
                present = true;
                break;
            }
        }
        if (present) following[followerId].erase(following[followerId].begin() + ind);
        return;
    }
};

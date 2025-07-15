class Twitter {
    private:
    int time = 0;
    unordered_map<int, unordered_set<int>> followDb;
    unordered_map<int, vector<pair<int, int>>> tweetsDb;    
    
    public:
        Twitter() {
        }
        
        void postTweet(int userId, int tweetId) {
            tweetsDb[userId].push_back({time, tweetId});
            time++;
        }
        
        vector<int> getNewsFeed(int userId) {
            auto comp = [](pair<int, int> &a, pair<int, int> &b) {
                return a.first > b.first;
            };
            priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> recentTweets(comp);
            vector<int> returnTweets;
            for (int followee: followDb[userId]) {
                if (followee == userId) continue;
                for (pair<int, int> tweet: tweetsDb[followee]) {
                    recentTweets.push(tweet);
                    if (recentTweets.size() > 10) recentTweets.pop();
                }
            }
            for (pair<int, int> tweet: tweetsDb[userId]) {
                recentTweets.push(tweet);
                if (recentTweets.size() > 10) recentTweets.pop();
            }
            while (!recentTweets.empty()) {
                returnTweets.push_back(recentTweets.top().second);
                recentTweets.pop();
            }
            reverse(returnTweets.begin(), returnTweets.end());
            return returnTweets;
        }
        
        void follow(int followerId, int followeeId) {
            followDb[followerId].insert(followeeId);
        }
        
        void unfollow(int followerId, int followeeId) {
            followDb[followerId].erase(followeeId);
        }
    };
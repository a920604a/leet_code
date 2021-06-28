class Twitter
{
private:
    // maintain two hash table ,and time to getNewsFeed 10 most recent tweet IDs
    unordered_map<int, set<int> > follows;    // userID mapping userID of followeeId
    unordered_map<int, map<int, int> > posts; // userID mapping [time mapping postID]
    int time;

public:
    /** Initialize your data structure here. */
    Twitter()
    {
        time = 0;
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId)
    {
        follow(userId, userId);
        posts[userId][time++] = tweetId;
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId)
    {
        vector<int> ret;
        map<int, int> m_top10;
        for (int s : follows[userId])
        {
            for (auto p : posts[s])
            { //traverse map
                m_top10[p.first] = p.second;
                // m_top10.insert({p.first, p.sacond});
                if (m_top10.size() > 10)
                    m_top10.erase(m_top10.begin());
            }
        }

        for (auto m : m_top10)
        {
            ret.emplace(ret.begin(), m.second);
        }
        return ret;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId)
    {
        follows[followerId].insert(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId)
    {
        if (followerId != followeeId)
        {
            follows[followerId].erase(followeeId);
        }
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
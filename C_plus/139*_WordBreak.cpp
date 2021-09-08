class Solution
{
public:
    unordered_map<string, bool> memo;
    bool check(string &s, unordered_set<string> &words)
    {
        if (words.count(s))
            return true;
        if (memo.count(s))
            return memo[s];
        for (int i = 1; i <= s.size(); ++i)
        {
            string left = s.substr(0, i);
            string right = s.substr(i, s.size());
            if (words.count(left) && check(right, words))
                return memo[s] = true;
        }
        return memo[s] = false;
    }
    bool wordBreak(string s, vector<string> &wordDict)
    {
        // option 0 brute force => time out
        // option 1 brute force + memo
        // unordered_set<string> words(wordDict.begin(), wordDict.end());
        // return check(s, words);

        // option 2 dp
        //      l   e   e   t   c   o   d   e
        //  t   f   f   f   f   f   f   f   f
        //  t   f   f   f   t   f   f   f   t
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 0; i < dp.size(); ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (dp[j] && words.count(s.substr(j, i - j)))
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp.back();
    }
};
class Solution
{
public:
    bool check(string s, unordered_set<string> &dict)
    {
        if (dict.count(s))
            return true;

        for (int i = 1; i <= s.size(); ++i)
        {
            string left = s.substr(0, i);
            string rest = s.substr(i, s.size());
            if (dict.count(left) && check(rest, dict))
            {
                return true;
            }
        }
        return false;
    }
    bool wordBreak(string s, vector<string> &wordDict)
    {
        // option 1 brute
        // unordered_set<string> dict(wordDict.begin(), wordDict.end());
        // return check(s, dict);

        // option 2
        // dp

        map<string, bool> memo;
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return check(s, dict, memo);
    }
    bool check(string s, unordered_set<string> &dict, map<string, bool> &memo)
    {
        if (dict.count(s))
            return true;
        if (memo.count(s))
            return memo[s];

        for (int i = 1; i <= s.size(); ++i)
        {
            string left = s.substr(0, i);
            string rest = s.substr(i, s.size());
            if (dict.count(left) && check(rest, dict, memo))
            {
                memo[s] = true;
                return true;
            }
        }
        memo[s] = false;
        return false;
    }
};
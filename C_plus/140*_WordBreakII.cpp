class Solution
{
public:
    unordered_map<string, vector<string> > memo;
    vector<string> helper(string s, vector<string> words)
    {
        if (memo.count(s))
            return memo[s];
        if (s.empty())
            return {""};

        vector<string> ret;
        for (string word : words)
        {
            if (s.substr(0, word.size()) != word)
                continue;
            vector<string> rem = helper(s.substr(word.size()), words);
            for (string str : rem)
            {
                ret.push_back(word + (str.empty() ? "" : " ") + str);
            }
        }
        return memo[s] = ret;
    }
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        // recursive
        return helper(s, wordDict);
    }
};
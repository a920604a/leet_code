class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int res = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            set<char> tmp;
            for (int j = i; j < s.size(); ++j)
            {
                if (tmp.find(s[j]) != tmp.end())
                    break;
                else
                    tmp.insert(s[j]);
            }
            res = max(res, int(tmp.size()));
        }
        return res;
    }
};
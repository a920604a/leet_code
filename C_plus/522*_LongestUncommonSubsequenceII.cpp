class Solution
{
public:
    bool checkSubs(string a, string b)
    {
        int i = 0;

        for (char c : b)
        {
            if (c == a[i])
                ++i;
            if (i == a.size())
                break;
        }
        return i == a.size();
    }
    int findLUSlength(vector<string> &strs)
    {
        int n = strs.size();
        int ret = -1;
        int j = 0;
        for (int i = 0; i < n; ++i)
        {
            for (j = 0; j < n; ++j)
            {
                if (i == j)
                    continue;
                if (checkSubs(strs[i], strs[j]))
                    break;
            }
            if (j == n)
                ret = max(ret, (int)strs[i].size());
        }
        return ret;
    }
};
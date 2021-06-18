class Solution
{
public:
    int titleToNumber(string columnTitle)
    {
        int ret = 0;
        for (char c : columnTitle)
        {
            ret *= 26;
            ret += (c - 'A' + 1);
        }
        return ret;
    }
};
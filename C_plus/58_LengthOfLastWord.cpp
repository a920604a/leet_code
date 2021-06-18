class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int ret = 0;
        int r = s.size() - 1;
        while (s[r] == ' ' && r > 0)
            r--;
        int l = 0;
        for (l = 0; l <= r; ++l)
        {
            ret++;
            if (s[l] == ' ')
                ret = 0;
        }
        return ret;
    }
};
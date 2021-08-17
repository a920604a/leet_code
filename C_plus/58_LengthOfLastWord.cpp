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

        //  option 2
        int l = -1, r = s.size() - 1;
        while (r > l && s[r] == ' ')
            r--;
        for (int i = 0; i <= r; ++i)
        {
            if (s[i] == ' ')
                l = i;
        }
        if (l == -1)
            return r + 1;
        return r - l;
    }
};
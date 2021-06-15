class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if (needle.empty())
            return 0;
        if (haystack.empty())
            return -1;
        if (haystack.size() < needle.size())
            return -1;
        for (int i = 0; i <= haystack.size() - needle.size(); ++i)
        {
            int tmp = 0;
            for (int j = 0; j < needle.size(); ++j)
            {
                if (haystack[i + j] == needle[j])
                    tmp++;
            }
            if (tmp == needle.size())
                return i;
        }
        return -1;
    }
};
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if (haystack.size() == 0 && needle.size() == 0)
            return 0;
        if (needle.size() > haystack.size())
            return -1;

        int ret = -1;
        for (int i = 0; i <= haystack.size() - needle.size(); ++i)
        {

            int tmp = 0;
            for (int j = 0; j < needle.size(); ++j)
            {
                if (haystack[i + j] != needle[j])
                    break;
                tmp++;
            }
            if (tmp == needle.size())
                return i;
        }

        return -1;
    }
};
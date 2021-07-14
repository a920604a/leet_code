class Solution
{
public:
    string longestPalindrome(string s)
    {
        // O(n^2)
        int start = 0;
        int maxlen = 0;
        int l = 0, r = 0;
        int n = s.size();
        for (int i = 0; i < n;)
        {
            int l = i, r = i;
            while (r < n - 1 && s[r] == s[r + 1])
                r++;
            i = r + 1;
            while (l > 0 && r < n && s[l - 1] == s[r + 1])
            {
                l--;
                r++;
            }

            if (maxlen < r - l + 1)
            {
                maxlen = r - l + 1;
                start = l;
            }
        }
        return s.substr(start, maxlen);
    }
};
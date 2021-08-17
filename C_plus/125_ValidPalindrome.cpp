class Solution
{
public:
    bool isPalindrome(string s)
    {

        // option 1
        int l = 0, r = s.size() - 1;
        while (l < r)
        {
            if (!Isdigits(s[l]))
                l++;
            else if (!Isdigits(s[r]))
                r--;
            else if ((s[l] - 'a' + 32) % 32 != (s[r] - 'a' + 32) % 32)
                return false;
            else
            {
                l++;
                r--;
            }
        }
        return true;

        // option 2
        int l = 0, r = s.size() - 1;
        while (l < r)
        {
            while (l < r && !isalnum(s[r]))
                r--;
            while (l < r && !isalnum(s[l]))
                l++;

            if (toupper(s[l]) == toupper(s[r]))
            {
                l++;
                r--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    bool Isdigits(char c)
    {
        if (c >= '0' && c <= '9')
            return true;
        else if (c - 'a' >= 0 && c - 'a' < 26)
            return true;
        else if (c - 'A' >= 0 && c - 'A' < 26)
            return true;
        else
            return false;
    }
};
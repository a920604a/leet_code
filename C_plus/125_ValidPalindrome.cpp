class Solution
{
public:
    bool isValid(char &c)
    {

        if (c >= '0' && c <= '9')
            return true;
        if (c >= 'a' && c <= 'z')
            return true;
        if (c >= 'A' && c <= 'Z')
            return true;
        return false;
    }
    bool isPalindrome(string s)
    {

        int l = 0, r = s.size() - 1;
        while (r > l && s[r] == ' ')
            r--;

        while (l < r)
        {
            while (l < r && !isValid(s[l]))
                l++;
            while (l < r && !isValid(s[r]))
                r--;
            if (tolower(s[l]) == tolower(s[r]))
            {
                l++;
                r--;
            }
            else
                return false;
        }
        return true;
    }
};
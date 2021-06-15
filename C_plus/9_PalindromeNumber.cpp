class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        if (x % 10 == 0 && x > 0)
            return false;
        int tmp = 0;
        while (x > tmp)
        {
            tmp *= 10;
            tmp += (x) % 10;
            x /= 10;
        }
        return (tmp == x) || (tmp / 10 == x);
    }
};
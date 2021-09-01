class Solution
{
public:
    bool hasAlternatingBits(int n)
    {
        int pre = (n & 1);
        n >>= 1;
        while (n)
        {
            if (pre == 0 && (n & 1) == 0)
                return false;
            if (pre * (n & 1) == 1)
                return false;
            pre = n & 1;
            n >>= 1;
        }
        return true;
    }
};
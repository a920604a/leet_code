class Solution
{
public:
    int trailingZeroes(int n)
    {
        // option 1
        // 看有幾個5，就有幾個0
        int ret = 0;
        while (n)
        {
            ret += n / 5;
            n /= 5;
        }
        return ret;

        // option 2
        // if(n==0) return 0;
        // return n/5 + trailingZeroes(n/5);
    }
};
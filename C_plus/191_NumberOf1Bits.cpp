class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        // option 1  bitwise
        // int ret = 0;
        // while(n){
        //     ret += (n&1);
        //     n >>=1; // n = n>>1;
        // }
        // return ret;

        // option 2
        int ret = 0;
        for (int i = 0; i < 32; ++i)
        {
            ret += (n % 2);
            n = n >> 1;
        }
        return ret;
    }
};
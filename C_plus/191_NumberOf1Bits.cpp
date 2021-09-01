class Solution
{
public:
    int hammingWeight(uint32_t n)
    {

        // bit manipulation can avoid overflow
        // option 1
        // int ret = 0;
        // for (int i = 0; i < 32; ++i)
        // {
        //     ret += (n % 2);
        //     n = n >> 1;
        // }
        // option 1.2  bitwise
        // int ret = 0;
        // while(n){
        //     ret += (n&1);
        //     n >>=1; // n = n>>1;
        // }
        // return ret;

        // option 2 make use of n & (n-1)=0 可以將最低位的1消除
        int ret = 0;
        while (n)
        {
            ret ++;
            n = n & (n - 1);
        }
        return ret;
    }
};
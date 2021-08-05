class Solution
{
public:
    int trailingZeroes(int n)
    {
        // option 1
        // 看有幾個5，就有幾個0 avoid overflow;
        int ret = 0;
        for(int d = n;d/5>0 ;d/=5){
            ret += d/5;
        }
        return ret;

        // option 2
        // if(n==0) return 0;
        // return n/5 + trailingZeroes(n/5);
    }
};
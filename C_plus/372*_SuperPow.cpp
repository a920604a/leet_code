class Solution
{
public:
    int base = 1337;
    int pow(int a, int k)
    {
        a %= base;
        int res = 1;
        for (int _ = 0; _ < k; _++)
        {
            // 這裡有乘法，可能溢位
            res *= a;
            // 對每次乘法结果取餘數
            res %= base;
        }
        return res;
    }
    int superPow(int a, vector<int> &b)
    {

        // option 1
        // a = 2 , b = [1,2]  ,  2048
        //  2^2 * superPow(a, [1])^10
        //  2^2 * 2^10 = 2048
        if (b.empty())
            return 1;
        int ret = pow(a, b.back());
        b.pop_back();
        ret *= pow(superPow(a, b), 10);
        return ret % base;
    }
};
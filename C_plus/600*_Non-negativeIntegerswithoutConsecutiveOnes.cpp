class Solution
{
public:
    int findIntegers(int n)
    {
        // k = 0 , 0
        // k = 1 , 0-1
        // k = 2 , 00-11
        // k = 3 , 000-111
        // k = 4 , 0000-1111

        // f(k) , k = 5 00000-11111 ==> 00000-01111 和 10000-10111，因為11000不成立。
        // f(5 ) = f(4) + f(3) , f(4) =  00000-01111 , f(3) = 10000-10111 = 000-111
        // f[] = 1 2 3 5 8 13 21 34 55
        // findIntegers(1) = f(0) + 1 = 2 , 1 = 1
        // findIntegers(2) = f(1) + 1 = 3 ,  2 = 10
        // findIntegers(3) = f(1) + f(0) = 3  , 3 = 11 ，在while迴圈中直接返回，因為出現連續兩個一
        // findIntegers(4) = f(2) + 1 = 4 ,  4 = 100
        // findIntegers(5) = f(2) + f(0) + 1 = 5,   5 = 101
        // findIntegers(6) = f(2) + f(1)  = 5,     6 = 110，在while迴圈中直接返回，因為出現連續兩個一

        int ret = 0, k = 31, pre = 0;
        vector<int> f(32, 0);
        f[0] = 1, f[1] = 2;
        for (int i = 2; i < 31; ++i)
        {
            f[i] = f[i - 1] + f[i - 2];
        }
        while (k >= 0)
        {
            if (n & (1 << k))
            {
                ret += f[k];
                if (pre)
                    return ret;
                pre = 1;
            }
            else
                pre = 0;
            k--;
        }
        return ret + 1;
    }
};
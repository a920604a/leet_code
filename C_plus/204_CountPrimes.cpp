/*
 * @Author: yuan
 * @Date: 2021-05-01 13:36:03
 * @LastEditTime: 2021-05-01 13:36:03
 * @FilePath: /C_plus/204_CountPrimes.cpp
 */
class Solution
{
public:
    int countPrimes(int n)
    {
        int ret = 0;
        if (n <= 1)
            return ret;
        vector<bool> v(n, true);
        v[0] = false;
        v[1] = false;
        for (int i = 2; i < sqrt(n); ++i)
        {
            if (v[i])
            {
                for (int j = 2; i * j < n; j++)
                {
                    v[i * j] = false;
                }
            }
        }
        for (bool b : v)
        {
            if (b)
                ret++;
        }

        return ret;
    }
};

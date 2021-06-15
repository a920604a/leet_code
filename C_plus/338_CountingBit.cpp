/*
 * @Author: yuan
 * @Date: 2021-05-02 11:43:39
 * @LastEditTime: 2021-05-02 11:43:40
 * @FilePath: /C_plus/338_CountingBit.cpp
 */
class Solution
{
public:
    vector<int> countBits(int num)
    {
        int count = 0;
        vector<int> ret;
        ret.push_back(count);
        for (int i = 1; i <= num; ++i)
        {
            int n = i;
            count = 0;
            while (n)
            {
                count += (n % 2); // count += (n&1);
                n /= 2;           // n = n>>1;
            }
            ret.push_back(count);
        }
        return ret;

        // vector<int> v{0};
        // for(int i=1;i<=num;++i)
        // {
        //     if(i%2==0) v.push_back(v[i/2]);
        //     else v.push_back(v[i/2]+1);
        // }
        // return v;
    }
};
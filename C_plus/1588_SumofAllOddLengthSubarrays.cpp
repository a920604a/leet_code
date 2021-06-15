/*
 * @Author: yuan
 * @Date: 2021-05-05 20:49:17
 * @LastEditTime: 2021-05-05 20:49:18
 * @FilePath: /C_plus/1588_SumofAllOddLengthSubarrays.cpp
 */
class Solution
{
public:
    int sumOddLengthSubarrays(vector<int> &arr)
    {
        int ret = 0;
        for (int i = 1; i <= arr.size(); i += 2)
        { // i=1,3,5,7,9...
            int k = 0;
            while (k + i - 1 < arr.size())
            {
                int sum = 0;
                vector<int> tmp(arr.begin() + k, arr.begin() + i + k);
                k++;
                for (int n : tmp)
                {
                    sum += n;
                }
                ret += sum;
            }
        }
        return ret;
    } 
};
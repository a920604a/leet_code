/*
 * @Author: yuan
 * @Date: 2021-05-04 19:21:12
 * @LastEditTime: 2021-05-04 19:21:20
 * @FilePath: /C_plus/905_SortArrayByParity.cpp
 */
class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &A)
    {
        // vector<int> res(A.size(),0);
        // int l=0,r=res.size()-1;
        // for(int i=0;i<A.size();++i){
        //     if(A[i]%2==0) res[l++] = A[i];
        //     else res[r--] = A[i];
        // }
        // return res;

        for (int j = 0, i = 0; j < A.size(); j++)
        {

            if (A[j] % 2 == 0)
            {
                swap(A[i++], A[j]);
            }
        }

        return A;
    }
};
class Solution
{
public:
    int countPrimes(int n)
    {
        // option 1 ，
        // 仍存在重複計算 i = 4, 4*2 =8, 4*3 =12，但這兩個數字已經在 i= 2 和 i=3 的 2*4 3*4 倍標記了
        //         vector<bool> visited(n, true);

        //         for(int i=2;i*i<n ;++i){
        //             if(visited[i]){
        //                 for(int j=2*i;j<n;j+=i){
        //                     visited[j] = false;
        //                 }
        //             }
        //         }
        //         int ret = 0;
        //         for(int i=2;i<n;++i){
        //             if(visited[i]) ret++;
        //         }
        //         return ret;

        // option 2  O(N * loglogN) time
        vector<bool> visited(n, true);

        for (int i = 2; i * i < n; ++i)
        {
            if (visited[i])
            {
                for (int j = i * i; j < n; j += i)
                {
                    visited[j] = false;
                }
            }
        }
        int ret = 0;
        for (int i = 2; i < n; ++i)
        {
            if (visited[i])
                ret++;
        }
        return ret;
    }
};
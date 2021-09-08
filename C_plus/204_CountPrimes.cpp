class Solution
{
public:
    int countPrimes(int n)
    {
        // option 1 ，
        // 仍存在重複計算 i = 4, 4*2 =8, 4*3 =12，
        // 但這兩個數字已經在 i= 2 和 i=3 的 2*4 3*4 倍標記了
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
        // Sieve of Eratosthenes algo
        // 2    4   6   8   10  12  14  16  18
        // 3    9   12  15  18  21  24  27  30
        // 4    16  20  24  28  32  36  40  44
        vector<bool> visited(n, true);

        for (int i = 2; i <= n / i; ++i)
        {
            if (visited[i])
            {
                for (int j = i * i; j < n; j += i) // 這樣比較快
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

    // option 3 
};
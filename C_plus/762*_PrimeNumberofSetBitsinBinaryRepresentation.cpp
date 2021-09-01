class Solution
{
public:
    int count(int n)
    {
        int ret = 0;
        while (n)
        {
            ret++;
            n = n & (n - 1);
        }
        return ret;
    }

    int countPrimeSetBits(int left, int right)
    {
        // option 1 O(nlogn) time and O(n) space
        //         vector<int> primes(right+1, true);
        //         primes[0] = false, primes[1] = false;
        //         for(int i = 2;i<=right ;++i){
        //             if(primes[i]){
        //                 for(int j = i+i;j<right ; j +=i) primes[j] = false;
        //             }
        //         }

        //         int ret = 0;
        //         for(int i=left ; i<=right ; ++i){
        //             int k = count(i);
        //             if(primes[k]) ret++;
        //         }
        //         return ret;

        // option 2 , 因為right 有範圍 < 10^6 < 2^20，所以只要統計是否是20以內的質數即可。
        // 20以內 ，只要不能被2或3整除一定是質數
        int ret = 0;
        set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        for (int i = left; i <= right; ++i)
        {
            int k = count(i);
            // int k = __builtin_popcount(i);
            if (primes.count(k))
                ret++;
        }
        return ret;
    }
};
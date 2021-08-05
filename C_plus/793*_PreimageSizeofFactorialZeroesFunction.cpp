class Solution
{
public:
    long trailingZeroes(long n)
    {
        // 給一個數返回該數階層後有多少的0
        // 遞增函數
        // input 0~4 => 0
        // input 5~9 => 1
        // input 10~14 => 2
        // input 15~19 => 3

        if (n == 0)
            return 0;
        long ret = 0;
        for (long d = n; d / 5 > 0; d /= 5)
        {
            ret += d / 5;
        }
        return ret;
    }
    int preimageSizeFZF(int k)
    {

        // option 1
        // brute force 果然 timeout
        // int ret = 0;
        // for(int i =0;i<=1e+9 ;++i){
        //     int eval = trailingZeroes(i);
        //     if(eval > k) break;
        //     if(eval == k) ret++;
        //     // if(eval < k) continue;
        // }
        // return ret;

        // binary search O(logK)
        // 因為單調trailingZeroes是遞增函數，那答案就相當於求
        // 二元搜尋右側邊界 - 二元搜尋右側邊界  +1
        return right_bound(k) - lower_bound(k) + 1;
    }
    int lower_bound(int k)
    {
        long l = 0, r = LONG_MAX;
        while (l < r)
        {
            long mid = l + (r - l) / 2; // avoid overflow
            long eval = trailingZeroes(mid);

            if (eval == k)
                r = mid;
            else if (eval > k)
                r = mid;
            else if (eval < k)
                l = mid + 1;
        }
        return l;
    }
    int right_bound(int k)
    {
        long l = 0, r = LONG_MAX;
        while (l < r)
        {
            long mid = l + (r - l) / 2; // avoid overflow
            long eval = trailingZeroes(mid);

            if (eval == k)
                l = mid + 1;
            else if (eval > k)
                r = mid;
            else if (eval < k)
                l = mid + 1;
        }
        return l - 1;
    }
};
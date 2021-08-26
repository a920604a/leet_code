class Solution
{
public:
    bool search(long l, long r, long target)
    {

        while (l <= r)
        {
            long mid = l + (r - l) / 2;
            if (mid * mid == target)
                return true;
            else if (mid * mid < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return false;
    }

    bool judgeSquareSum(int c)
    {

        // option 1 two pointer O(n)
        //  5 = 1*1 + 2*2
        // 10 = 1*1 + 3*3
        // 13 = 2*2 + 3*3
        //
        // 找哪兩個數字
        int l = 0, r = sqrt(c);
        // l 可以等於 r
        while (l <= r)
        {
            // overflow
            // int sum = l*l + r*r;
            // if(sum == c) return true;
            // else if(sum < c) l++;
            // else r--;

            // avoid overflow
            int sum = c - l * l;
            if (sum == r * r)
                return true;
            else if (sum > r * r)
                l++;
            else
                r--;
        }
        return false;

        // option 2 binary search O(logn)
        bool ret = false;

        if (c < 0)
            return ret;

        if (c == 0 || c == 1)
            return true;

        for (long long i = 0; i * i <= c; ++i)
        {
            long target = c - i * i;

            // 能不能找出 一個數字 其平方為 target，
            if (search(0, target, target))
            {
                ret = true;
                break;
            }
        }

        return ret;
    }
};
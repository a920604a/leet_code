class Solution
{
public:
    double myPow(double x, int n)
    {

        double ret = x;
        if (n == 0)
            ret = 1;
        else if (n == 1)
            return ret;
        else if (x == 1)
            return x;
        else if (x == -1)
            return n < 0 ? -x : x;
        else if (n > 1)
        {
            for (int i = 0; i < n - 1; ++i)
            {
                if (ret * x >= 10000)
                    return 10000;
                if (ret * x <= -10000)
                    return -10000;
                if (ret * x == 0)
                    return 0;
                ret *= x;
            }
        }
        // n < 1
        else if (n < 1)
        {
            ret = 1 / x;
            for (int i = n; i < -1; i++)
            {
                // if(ret*(1/x) <= DBL_MIN) return DBL_MIN;
                if (ret * (1 / x) == 0)
                    return 0;
                ret *= (1 / x);
            }
        }
        return ret;
    }
};
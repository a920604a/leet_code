class Solution
{
public:
    bool isUgly(int n)
    {
        if (n < 1)
            return false;
        int m = n;

        while (m % 5 == 0)
            m /= 5;
        while (m % 3 == 0)
            m /= 3;
        while (m % 2 == 0)
            m /= 2;
        return m == 1;
    }
};
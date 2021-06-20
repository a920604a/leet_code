class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        int first = 0, second = 0, third = 0;
        long max_1 = LONG_MIN, max_2 = LONG_MIN, max_3 = LONG_MIN;
        for (int n : nums)
        {
            if (n == max_1 || n == max_2 || n == max_3)
                continue;

            if (n > max_1)
            {
                max_3 = max_2;
                max_2 = max_1;
                max_1 = n;
            }
            else if (n > max_2)
            {
                max_3 = max_2;
                max_2 = n;
            }
            else if (n > max_3)
            {
                max_3 = n;
            }
        }

        return max_3 == LONG_MIN ? max_1 : max_3;
    }
};
class Solution
{
public:
    int candy(vector<int> &ratings)
    {

        //   1   0   2
        //l  1   1   2
        //r  2   1   2

        //      1   2   2
        //      1   2   1
        //
        int n = ratings.size();
        vector<int> nums(n, 1);
        for (int i = 0; i < n - 1; i++)
        {
            if (ratings[i + 1] > ratings[i])
                nums[i + 1] = nums[i] + 1;
        }

        for (int i = n - 1; i > 0; --i)
        {
            if (ratings[i - 1] > ratings[i])
                nums[i - 1] = max(nums[i - 1], nums[i] + 1);
        }
        int ret = 0;
        for (int n : nums)
            ret += n;
        return ret;
    }
};
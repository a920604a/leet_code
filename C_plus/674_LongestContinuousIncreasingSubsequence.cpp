class Solution
{
public:
    int findLengthOfLCIS(vector<int> &nums)
    {

        int ret = 0, temp = 1;
        int n = nums.size();
        if (n == 1)
            return 1;
        for (int i = 1; i < n; ++i)
        {
            if (nums[i] > nums[i - 1])
                temp++;
            else
            {
                ret = max(ret, temp);
                temp = 1;
            }
        }
        return max(ret, temp);
    }
};
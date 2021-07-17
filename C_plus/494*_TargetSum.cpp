class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int res = 0;
        helper(nums, target, 0, res);
        return res;
    }
    void helper(vector<int> &nums, long target, int start, int &ret)
    {

        if (start >= nums.size())
        {
            if (target == 0)
                ret++;
            return;
        }
        helper(nums, target - nums[start], start + 1, ret);
        helper(nums, target + nums[start], start + 1, ret);
    }
};
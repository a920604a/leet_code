class Solution
{
public:
    int minMoves2(vector<int> &nums)
    {

        // 排序後 ，取差值
        sort(nums.begin(), nums.end());

        int i = 0, j = nums.size() - 1;
        int ret = 0;
        while (i < j)
        {
            ret += nums[j--] - nums[i++];
        }
        return ret;
    }
};
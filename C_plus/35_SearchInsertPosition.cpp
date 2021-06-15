class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        if (target < nums[0])
            return 0;
        if (target > nums[nums.size() - 1])
            return nums.size();
        int l = 0;
        while (l < nums.size())
        {
            if (nums[l] == target)
                return l;
            else if (nums[l] < target)
                l++;
            else
            {
                return l;
            }
        }
        return l;
    }
};
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return 1;
        int i = 0;
        for (int j = 1; j < nums.size(); ++j)
        {
            if (nums[j] != nums[i])
            {
                i++;
                int tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
            }
        }
        return i + 1;
    }
};
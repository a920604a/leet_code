class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {

        if (nums.empty())
            return 0;
        int slow = 0, fast = 0;
        while (fast < nums.size())
        {

            if (nums[fast] != nums[slow])
            {
                slow++;
                // 維護nums[0...slow] 無重複就好
                nums[slow] = nums[fast];
            }

            fast++;
        }

        return slow + 1;
    }
};
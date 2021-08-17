class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        int slow = 0, count = 1, fast = 1;
        while (fast < nums.size())
        {

            if (nums[fast] == nums[slow] && count == 0)
                fast++;
            else
            {
                if (nums[fast] == nums[slow])
                    count--;
                else
                    count = 1;

                nums[++slow] = nums[fast++];
            }
        }
        return slow + 1;
    }
};
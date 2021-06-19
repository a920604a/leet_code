class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        // two pointer

        int n = nums.size(), a = -1;
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] != 0)
            { // sawp a+1, b
                swap(nums[++a], nums[i]);
            }
        }
    }
};
class Solution
{
public:
    int smallestEqual(vector<int> &nums)
    {
        // O(n) time
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            if (i % 10 == nums[i])
                return i;
        }
        return -1;
    }
};
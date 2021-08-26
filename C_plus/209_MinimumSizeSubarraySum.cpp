class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {

        // O(n) time  sliding window
        int l = 0, r = 0;
        int ret = INT_MAX;
        int window = 0;
        while (r < nums.size())
        {
            int c = nums[r++];

            window += c;
            while (window >= target)
            {

                if (window >= target)
                {
                    ret = min(ret, r - l);
                }

                int d = nums[l++];
                window -= d;
            }
        }
        return ret == INT_MAX ? 0 : ret;
    }
};
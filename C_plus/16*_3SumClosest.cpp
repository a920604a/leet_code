class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int ret = nums[0] + nums[1] + nums[2];
        int cand = 0;
        for (int i = 0; i < nums.size() - 2; ++i)
        {
            int j = i + 1, k = nums.size() - 1;
            while (j < k)
            {
                cand = nums[i] + nums[j] + nums[k];
                if (cand == target)
                    return cand;

                else if (cand < target)
                {
                    j++;
                }
                else if (cand > target)
                {
                    k--;
                }
                if (abs(target - ret) > abs(target - cand))
                    ret = cand;
            }
        }
        return ret;
    }
};
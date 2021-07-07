class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        vector<int> ret;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            int t = -1;
            for (int j = i + 1; j < i + n; j++)
            {
                if (nums[j % n] > nums[i])
                {
                    t = nums[j % n];
                    break;
                }
            }
            ret.push_back(t);
        }
        return ret;
    }
};
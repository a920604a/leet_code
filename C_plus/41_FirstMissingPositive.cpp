class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {

        vector<int> vec(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] > 0 && nums[i] < nums.size() + 1)
                vec[nums[i]]++;
        }
        for (int i = 1; i < vec.size(); ++i)
        {
            if (vec[i] == 0)
            {
                return i;
            }
        }
        return vec.size();
    }
};
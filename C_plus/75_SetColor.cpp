class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        if (nums.size() == 1)
            return;
        vector<int> v = {0, 0, 0};
        for (int n : nums)
        {
            v[n] += 1;
        }
        int j = 0, i = 0;
        while (j < v.size())
        {
            if (v[j])
            {
                nums[i++] = j;
                v[j]--;
            }
            else
            {
                j++;
            }
        }
        return;
    }
};
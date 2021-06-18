class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        // option 1  O(nlogn)
        // sort(nums.begin(), nums.end());
        // return nums[nums.size()/2];

        // option 2 O(n)
        int ret;
        int count = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (count == 0 || nums[i] == ret)
            {
                ret = nums[i];
                count++;
            }
            else
                count--;
        }
        return ret;
    }
};
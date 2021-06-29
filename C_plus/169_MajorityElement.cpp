class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        // option 1  O(nlogn)
        // sort(nums.begin(), nums.end());
        // return nums[nums.size()/2];

        // option 2 O(n) and O(1) space
        int ret;
        int count = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (count == 0)
            {
                ret = nums[i];
                count++;
            }
            else if (nums[i] == ret)
                count++;
            else
                count--;
        }
        return ret;
    }
};
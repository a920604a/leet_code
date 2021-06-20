class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int ret = 0, tmp = 0;
        for (int i : nums)
        {
            if (i == 0)
            {
                ret = max(ret, tmp);
                tmp = 0;
            }
            else
                tmp++;
        }
        return max(ret, tmp);
    }
};
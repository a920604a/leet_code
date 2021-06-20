class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        map<int, int> m{{0, -1}}; // use map to record sum-start pt mapping
        int ret, sum = 0;         // 遇一加一，遇零減一
        for (int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i] == 1 ? 1 : -1;
            if (m.count(sum))
            {
                // cout<<i<<" "<<m[sum]<<endl;
                ret = max(ret, i - m[sum]);
            }
            else
                m[sum] = i;
        }
        return ret;
    }
};
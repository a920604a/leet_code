class Solution
{
public:
    int arrayNesting(vector<int> &nums)
    {
        // option 1 O(n) time and O(n) space
        int n = nums.size();
        vector<bool> visited(n, false);
        int ret = 0;
        for (int i = 0; i < n; ++i)
        {
            int j = i;
            int cand = 0;
            while (visited[j] == false)
            {
                cand++;
                visited[j] = true;
                j = nums[j];
            }
            ret = max(ret, cand);
        }
        return ret;
    }
};
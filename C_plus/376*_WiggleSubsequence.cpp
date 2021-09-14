class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {

        // dp
        //      1   7   4   9   2   5
        //up    1   2   2   4   2   6
        //down  1   1   3   1   5   5
        int n = nums.size();
        vector<int> up(n, 1), down(n, 1);
        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (nums[i] > nums[j])
                    up[i] = max(down[j] + 1, up[i]);
                else if (nums[i] < nums[j])
                    down[i] = max(up[j] + 1, down[i]);
            }
            cout << up[i] << " " << down[i] << endl;
        }
        return max(up.back(), down.back());
        // option 2 greedy

        // int p = 1, q = 1, n = nums.size();
    }
};
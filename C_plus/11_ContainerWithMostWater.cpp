class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        // two pointer O(n)
        int ret = 0;
        int l = 0, r = height.size() - 1;
        while (l < r)
        {
            int container = min(height[l], height[r]) * (r - l);
            ret = max(ret, container);
            if (height[l] > height[r])
                r--;
            else
                l++;
        }
        return ret;
    }
};
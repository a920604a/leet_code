class Solution
{
public:
    int heightChecker(vector<int> &heights)
    {
        // option 1  O(nlogn)
        int ret = 0;
        vector<int> vec(heights.begin(), heights.end());
        sort(vec.begin(), vec.end());
        for (int i = 0; i < vec.size(); ++i)
        {
            if (heights[i] != vec[i])
                ret++;
        }
        return ret;
    }
};
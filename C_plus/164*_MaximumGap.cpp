class Solution
{
public:
    int maximumGap(vector<int> &nums)
    {
        // option 1 O(nlogn)
        // if(nums.size()==1) return 0;
        // int ret = 0, n = nums.size();
        // sort(nums.begin(), nums.end()); // O(nlogn)
        // for(int i=1;i<n;i++){
        //     ret = max(ret, nums[i]-nums[i-1]) ;
        // }
        // return ret;

        // option 2  O(n) time and O(n) space
        // 桶排序

        int n = nums.size();
        if (n < 2)
            return 0;
        auto lu = minmax_element(nums.begin(), nums.end());
        int global_min = *lu.first, global_max = *lu.second;
        int gap = max((global_max - global_min) / (n - 1), 1);
        int m = (global_max - global_min) / gap + 1;
        vector<int> bucketsMin(m, INT_MAX);
        vector<int> bucketsMax(m, INT_MIN);
        for (int num : nums)
        {
            int k = (num - global_min) / gap;
            if (num < bucketsMin[k])
                bucketsMin[k] = num;
            if (num > bucketsMax[k])
                bucketsMax[k] = num;
        }

        int i = 0, j;
        gap = bucketsMax[0] - bucketsMin[0];
        while (i < m)
        {
            j = i + 1;
            while (j < m && bucketsMin[j] == INT_MAX && bucketsMax[j] == INT_MIN)
                j++;
            if (j == m)
                break;
            gap = max(gap, bucketsMin[j] - bucketsMax[i]);
            i = j;
        }
        return gap;
    }
};
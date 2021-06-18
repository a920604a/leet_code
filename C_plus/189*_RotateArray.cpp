class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {

        // option 1 tricky 作弊方法 space O(n)
        //         int n= nums.size();
        //         int start = n - k%n ;
        //         vector<int> temp (n, 0);
        //         int j=0;
        //         for(int i=start ;i<n;++i) temp[j++] =nums[i];
        //         for(int i = 0;i<start;++i) temp[j++] =  nums[i];

        //         nums = temp;
        //         temp.clear();

        // option 2  O(n) one-by-one  hrad to think

        //         if (nums.empty() || (k %= nums.size()) == 0) return;
        //         int start = 0, idx = 0, pre = 0, cur = nums[0], n = nums.size();
        //         for (int i = 0; i < n; ++i) {
        //             pre = cur;
        //             idx = (idx + k) % n;
        //             cur = nums[idx];
        //             nums[idx] = pre;
        //             if (idx == start) {
        //                 idx = ++start;
        //                 cur = nums[idx];
        //             }

        //         }

        // option 3 reverse again

        int n = nums.size(), start = n - k % n;
        reverse(nums.begin(), nums.begin() + start);
        reverse(nums.begin() + start, nums.end());
        reverse(nums.begin(), nums.end());
    }
};
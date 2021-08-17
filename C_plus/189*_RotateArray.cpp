class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {

        // option 1 tricky 作弊方法 space O(n)
        //         int n = nums.size();
        //         k = k%n;
        //         int p = n-k;
        //         vector<int> vec(n,0);
                
        //         for(int i=0;i<n;++i){
        //             vec[i] = nums[(p+n)%n];
        //             p++;
        //         }
        //         nums = vec;
        //         vec.clear();

        // option 2  O(n) one-by-one  hard to think

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

        // option 3 reverse 

        int n = nums.size(), start = n - k % n;
        reverse(nums.begin(), nums.begin() + start);
        reverse(nums.begin() + start, nums.end());
        reverse(nums.begin(), nums.end());
    }
};
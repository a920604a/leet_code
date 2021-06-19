class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        // option 1
        // O(n*logn) O(1) extra space
        // sort(nums.begin(), nums.end()); // O(nlogn)
        // int ans = 0;
        // for(int i=0;i<nums.size();++i){
        //     if(ans!=nums[i]) break;
        //     ans ++;
        // }
        // return ans;

        // option 2
        // math , O(1) extra space
        // int total = nums.size()*(nums.size()+1)/2;
        // for(int a:nums) total-=a;
        // return total;

        //option 3 bit-operation
        // int ans = 0;
        // for(int a:nums) ans ^=a;
        // return ans;

        // option 2
        // binary search

        int m = nums.size(), left = 0, right = m;
        sort(nums.begin(), nums.end());
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] > mid)
                right = mid;
            else
                left = mid + 1;
        }
        return right;
    }
};
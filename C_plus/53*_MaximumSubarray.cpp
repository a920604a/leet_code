class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        // option1 brute
        // int ret = nums[0];
        // for(int i=0;i<nums.size();++i){
        //     int total = 0;
        //     for(int j=i;j<nums.size();++j){
        //         total += nums[j];
        //         ret = max(ret, total);
        //     }
        // }
        // return ret;

        // option 2 O(n)
        // return GetMax(nums, 0, nums.size()-1);

        // option 3 Kadane’s Algorithm O(n) simplify option 1
        int n = nums.size(), local_max = 0;
        int global_max = INT_MIN;
        for (int i = 0; i < n; ++i)
        {
            local_max = max(nums[i], nums[i] + local_max);
            if (local_max > global_max)
            {
                global_max = local_max;
            }
        }
        return global_max;
    }

    //     int GetMax(vector<int>& nums,int l ,int r){

    //         if(l>=r) return nums[l];
    //         int mid = (l+r)/2;
    //         int lmax = GetMax(nums, l, mid-1);
    //         int rmax = GetMax(nums, mid+1, r);
    //         int mmax = nums[mid];
    //         int temp = nums[mid];
    //         for(int i=mid-1 ; i>=l; i--){

    //             temp += nums[i];
    //             mmax  = max(mmax, temp);
    //         }

    //         temp = mmax;
    //         for(int i = mid+1;i<=r;++i){

    //             temp += nums[i] ;
    //             mmax = max(mmax, temp);
    //         }
    //         return max(mmax , max(lmax, rmax));

    //     }
};
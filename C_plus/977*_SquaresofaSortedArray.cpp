class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        // option 1 O(nlogn) sorted algorithm
        // int n = nums.size();
        // vector<int> ret;
        // for(int i:nums) ret.emplace_back(i*i);
        // sort(ret.begin(),ret.end());
        // return ret;

        // option 2  O(n) two pointer
        // int n = nums.size();
        // vector<int> ret;
        // int l =0,r=n-1;
        // while(l<=r){
        //     if(pow(nums[l],2) >= pow(nums[r],2)){
        //         ret.emplace(ret.begin(), pow(nums[l],2));
        //         l++;
        //     }
        //     else{
        //         ret.emplace(ret.begin(), pow(nums[r],2));
        //         r--;
        //     }
        // }
        // return ret;

        // option 3 simplify faster option 2

        int n = nums.size();
        vector<int> ret(n, 0);
        int l = 0, r = n - 1;

        for (int k = n - 1; k > -1; --k)
        {
            if (abs(nums[l]) >= abs(nums[r]))
            {
                ret[k] = nums[l] * nums[l];
                l++;
            }
            else
            {
                ret[k] = nums[r] * nums[r];
                r--;
            }
        }
        return ret;
    }
};
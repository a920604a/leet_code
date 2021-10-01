class Solution
{
public:
    vector<int> sortArrayByParityII(vector<int> &nums)
    {

        // vector<int> ret = nums;
        // int n = nums.size();
        // int j=0,k=1;
        // for(int i=0;i<n;++i){
        //     if(nums[i]%2==0){
        //         ret[j] = nums[i];
        //         j+=2;
        //     }
        //     else{
        //         ret[k] = nums[i];
        //         k+=2;
        //     }
        // }
        // return ret;

        int i = 0, j = 1;
        int n = nums.size();
        while (i < n && j < n)
        {
            while (i < n && nums[i] % 2 == 0)
                i += 2;
            while (j < n && nums[j] % 2 != 0)
                j += 2;
            if (i < n)
                swap(nums[i], nums[j]);
        }
        return nums;
    }
};
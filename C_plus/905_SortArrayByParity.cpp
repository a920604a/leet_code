class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        // option 1 O(n) two pointer

        //         int l=0,r=nums.size()-1;
        //         while(l<r){

        //             if(nums[l]%2!=0 && nums[r]%2==0){
        //                 swap(nums[l], nums[r]);
        //                 l++;
        //                 r--;
        //             }
        //             else if(nums[l]%2==0) l++;
        //             else r--;
        //         }
        //         return nums;

        // option 2  simplify version 1
        for (int i = 0, j = 0; i < nums.size(); ++i)
        {
            if (nums[i] % 2 == 0)
            {
                swap(nums[j++], nums[i]);
            }
        }
        return nums;
    }
};
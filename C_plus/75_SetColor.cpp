class Solution
{
public:
    void sortColors(vector<int> &nums)
    {

        // option 1 insert sort
        //         for(int i =1;i<nums.size();++i){
        //             int key = nums[i];
        //             int j = i-1;
        //             while(j>=0 && key<=nums[j]){
        //                 nums[j+1] = nums[j];
        //                 j--;
        //             }
        //             nums[j+1]=key;

        //         }
        //         for(int n:nums) cout<<n<<" ";

        // option 2 create vector to record
        vector<int> vec = {0, 0, 0};
        for (int n : nums)
            vec[n]++;
        int j = 0;
        for (int i = 0; i < nums.size();)
        {
            if (vec[j] > 0)
            {
                nums[i] = j;
                vec[j]--;
                ++i;
            }
            else
                j++;
        }
    }
};
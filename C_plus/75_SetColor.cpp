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

        // option 2 create vector to record
        // option cheap O(n)
        vector<int> his(3, 0);
        for (int n : nums)
            his[n]++;
        for (int i = 0, j = 0; i < nums.size(); ++i)
        {
            while (his[j] == 0)  j++;
            his[j]--;
            nums[i] = j;
        }

        // option 3 two pointer
        int n = nums.size();
        int red = 0, blue = n - 1;
        for (int i = 0; i <= blue; ++i)
        {
            if (nums[i] == 0)
            {
                swap(nums[i], nums[red++]);
            }
            else if (nums[i] == 2)
            {
                swap(nums[i--], nums[blue--]);
            }
        }
    }
};
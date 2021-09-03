class Solution
{
public:
    int getMaxLen(vector<int> &nums)
    {
        //        1   -2  -3  4
        //mx      1    0   3  4
        //mn      0    2   1  2

        //      0   1   -2  -3  -4
        //mx    0   1    0   3   4
        //mn    0   0    2   1   2
        // option 1 O(n) time ans O(n) space
        // dp
        // int n = nums.size();
        // vector<int> mx(n,0), mn(n,0);
        // if(nums[0]>0){
        //     mx[0] = 1;
        // }
        // else if(nums[0]<0){
        //     mn[0] = 1;
        // }
        // int ret = mx[0];
        // //  遇到正數 mx[i] = mx[i-1]+1 , mn[i] = mn[i-1]+1;
        // //  遇到負數 mx[i] = mn[i-1]+1 , mn[i] = mx[i-1]+1;
        // for(int i =1;i<n;++i){
        //     if(nums[i]==0){
        //         mx[i] = mn[i] = 0;
        //     }
        //     else if(nums[i]>0){
        //         mx[i] = mx[i-1]+1;
        //         if(mn[i-1]>0) mn[i] = mn[i-1]+1;// max(mn[i-1]+1, mn[i]);
        //     }
        //     else{
        //         mn[i] = mx[i-1] +1 ;
        //         if(mn[i-1]>0) mx[i] = mn[i-1]+1 ; //max(mn[i-1]+1, mx[i]);
        //     }
        //     ret = max(ret, mx[i]);
        // }
        // return ret;

        // option 2 O(n) time ans O(1) space
        // reduce dp
        int p = 0, n = 0, ret = 0;
        for (int x : nums)
        {
            if (x == 0)
            {
                p = n = 0;
            }
            else if (x > 0)
            {
                p = p + 1;
                if (n)
                    n++;
            }
            else
            {
                int tmp = p;
                if (n)
                    p = n + 1;
                else
                    p = 0;
                n = tmp + 1;
            }
            ret = max(ret, p);
        }
        return ret;
    }
};
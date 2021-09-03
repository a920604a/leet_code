class Solution
{
public:
    int maxRotateFunction(vector<int> &nums)
    {
        // option 0 O(n^2) time out
        // int n= nums.size();
        // int ret = INT_MIN;
        // for(int i=0;i<n;++i){
        //     int k = i;
        //     int f = 0;
        //     for(int a:nums){
        //         if(k>=n) k=0;
        //         f += k*a;
        //         k++;
        //     }
        //     ret = max(ret, f);
        // }
        // return ret;

        // option 1 math
        int total = 0, f = 0, n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            total += nums[i];
            f += (i * nums[i]);
        }
        int ret = f;
        // f_0 = 0A + 1B + 2C + 3D
        // f_1 = 0D + 1A + 2B + 3C
        // f_2 = 0C + 1D + 2A + 3B
        // f_3 = 0B + 1C + 2D + 3A
        // sum = 1A + 1B + 1C + 1D
        // f_1 = f_0 + sum - 4D
        // f_2 = f_1 + sum - 4C
        // f_3 = f_2 + sum - 4B
        // f(i) = f(i-1) + sum - n*A[n-i];
        for (int i = 1; i < n; ++i)
        {
            f = f + total - n * nums[n - i];
            ret = max(ret, f);
        }
        return ret;
    }
};
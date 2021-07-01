class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {

        // O(n) time and O(n) space
        // 用兩組陣列維護 最大及最小值。
        //         if(nums.size()<3) return false;
        //         int n = nums.size();
        //         vector<int> mn(n, INT_MAX), mx(n, INT_MIN);

        //         for(int i=1;i<n;i++){
        //             mn[i] = min( nums[i-1], mn[i-1]);
        //         }
        //         for(int i=n-2;i>-1;i--){
        //             mx[i] = max(nums[i+1], mx[i+1]);
        //         }
        //         for(int i=1;i<n-1;++i){
        //             if( mn[i]<nums[i] && nums[i]< mx[i]) return true;
        //         }
        //         return false;

        // O(n) time and O(1) space
        // two pointer 太難了！！
        // 維護兩個變數m1 m2，初始值都為最大值，遍歷每個元素，更新兩變數
        // 其中一個存至今最小值m1，另一個變數m2，當 遍歷的元素介於兩變數間，更新此變數
        // 遍歷元素大於m2，代表有Triplet子序列存在
        int n = nums.size();
        int m1 = INT_MAX, m2 = INT_MAX;
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] <= m1)
                m1 = nums[i];
            else if (nums[i] > m1 && nums[i] <= m2)
                m2 = nums[i];
            else
                return true;
        }

        return false;
    }
};
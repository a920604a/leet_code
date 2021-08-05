class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        // option 1 O(n) time and O(n) space
        
        // int n =nums.size();
        // vector<int> vec(n+1,false);
        // for(int n:nums) vec[n]=true;
        // for(int i=0;i<n;++i){
        //     if(vec[i]==false) return i;
        // }
        // return n;
        
        // option 2 O(n) time and O(1) space may be overflow
        // use math
        // int total = nums.size() * (nums.size()+1)/2;
        // for(int n:nums) total -=n;
        // return total;
        

        // option 3  O(n) time and O(1) space
        //  ^ operation ，針對只有一個數字
        // a ^ a = 0 , a ^ 0 = a
        // 因為 ^有交換率，假設每個數字都放對位置，index^val 都做完應該為0
        //  0   1   2   
        //  3   0   1
        //  3^(0^3)^(1^0)^(2^1)
        //  3^3^1^3 = 2
        int ret = nums.size();
        for(int i=0;i<nums.size() ;++i){
            ret ^= i^nums[i];
        }
        return ret;

        // option 4  O(n) time and O(1) space
        // use math
        //  3   0   1   
        // 因為加法滿足交換率和結合率，所以可以把成對的數字消去
        // ret = 3 + (0-3) + (1-0) + (2-1) =  3 + - 3 (0-0) + (1-1) + 2  = 2
        int n = nums.size();
        int ret = 0;
        ret += n-0;
        for(int i=0;i<n;++i){
            ret += i - nums[i];
        }
        return ret;
        // option 5
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
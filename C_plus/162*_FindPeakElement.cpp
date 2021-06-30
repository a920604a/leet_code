class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        // option 1 brute O(n)
        // int n=nums.size();
        // if (nums.size() == 1) return 0;
        // for(int i=0;i<n;++i){
        //     if(i==0 || i==n-1){
        //         if(i==0 && nums[i]>nums[i+1]) return i;
        //         else if(i==n-1 && nums[i]> nums[i-1]) return i;
        //     }
        //     else{
        //         if( nums[i]>nums[i-1] && nums[i]>nums[i+1]) return i;
        //     }
        // }
        // return -1;

        // option 2 simplify option 1 , 因為nums[i] != nums[i + 1]，直接在兩端加入最小值
        // if (nums.size() == 1) return 0;
        // nums.insert(nums.begin(), INT_MIN);
        // nums.push_back(INT_MIN);
        // for (int i = 1; i < (int)nums.size() - 1; ++i) {
        //     if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) return i - 1;
        // }
        // return -1;

        // option 3 一定存在至少一個山峰
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] < nums[i - 1])
                return i - 1;
        }
        return nums.size() - 1;

        // option 4 因為題目限制O(nlogn) 讓我想到 binary search，直接在兩端加入最小值，但返回值需要注意mid-1
        // int n=nums.size();
        // if(n<2) return 0;
        // nums.insert(nums.begin(), INT_MIN);
        // nums.push_back(INT_MIN);
        // return BinarySearch(nums, nums.size() );

        // option 5 簡化 option 4
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] < nums[mid + 1])
                l = mid + 1;
            else
                r = mid;
        }
        return r;
    }
    int BinarySearch(vector<int> &nums, int n)
    {

        int l = 0, r = n - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            cout << mid << endl;
            if (mid - 1 >= 0 && mid + 1 <= n - 1)
            {
                if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
                    return mid - 1;
                else if (nums[mid - 1] > nums[mid] && nums[mid] > nums[mid + 1])
                    r = mid;
                else
                    l = mid + 1;
            }
            else
                break;
        }

        return r;
    }
};
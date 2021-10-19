class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        // version 1
        // int l = 0, r= nums.size()-1; // 注意
        // 搜索區間[l, r]
        // while(l<=r){
        //     int mid = l + (r-l)/2;
        //     if(nums[mid] == target) return mid;
        //     else if(nums[mid]< target) l = mid+1; // 注意
        //     else if(nums[mid]>target) r= mid-1; // 注意
        // }
        // return -1;

        // version 2
        int l = 0, r = nums.size();
        // 搜索區間[l, r)
        while (l < r)
        { //  終止條件 l==r
            int mid = l + (r - l) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                l = mid + 1;
            else if (nums[mid] > target)
                r = mid;
        }
        return nums[l] == target ? l : -1;

        // option 3 left bound
        int n = nums.size();
        int l = 0, r = n;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target)
                r = mid;
            else if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid;
        }
        return l < n && nums[l] == target ? l : -1;

        // right bound
        // int l = 0, r = nums.size();
        // while(l<r){
        //     int mid = l + (r-l)/2;
        //     if(nums[mid] == target) l=mid +1; //return mid;
        //     else if(nums[mid]< target) l = mid +1;
        //     else r = mid ;
        // }
        // if(l==0) return -1;
        // return nums[l-1]==target?l-1:-1;

        // combine left and right bound
        int l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target)
            {
                // return mid;
                r = mid - 1; // left bound
                // l = mid+1 ; // right bound
            }
            else if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        // left bound
        if (l >= nums.size() || nums[l] != target)
            return -1;
        return l;
        //right bound
        // if(r<0 || nums[r]!=target) return -1;
        // return r;
    }
};
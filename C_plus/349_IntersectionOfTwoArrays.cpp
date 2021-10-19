class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        // option 1 O(nlogn) time and O(n) space
        //         set <int> tmp(nums1.begin(), nums1.end());
        //         set <int> ret;
        //         for(int n:nums2) if(tmp.find(n)!=tmp.end()) ret.insert(n);
        //         return vector<int> (ret.begin(), ret.end()); // convert set to vector

        // option 2
        // two pointer O(nlogn) time and O(1) space
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> ret;
        int l = 0, r = 0;
        while (l < nums1.size() && r < nums2.size())
        {
            if (nums1[l] == nums2[r])
            {
                if (ret.empty() || ret.back() != nums1[l])
                    ret.push_back(nums1[l]);
                l++;
                r++;
            }
            else if (nums1[l] < nums2[r])
                l++;
            else
                r++;
        }
        return ret;

        // option 3
        // binary search
        // O(nlogn)
        set<int> ret;
        sort(nums1.begin(), nums1.end());
        for (int n : nums2)
        {
            if (BinarySearch(nums1, n))
                ret.insert(n);
        }

        return vector<int>(ret.begin(), ret.end());

        // option 4 O(n) time and O(1) space
        vector<int> ret;
        vector<bool> his(1000, false);
        for (int n : nums1)
            his[n] = true;
        for (int n : nums2)
        {
            if (his[n])
                ret.push_back(n);
            his[n] = false;
        }
        return ret;
    }
    bool BinarySearch(vector<int> &nums, int target)
    {

        int l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (target == nums[mid])
                return true;
            else if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return false;
    }
};
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        // option 1
        // O(nlogn)
        // sort(nums.begin(), nums.end());
        // return nums[nums.size()-k];

        // option 2
        // priority queue  O(nlogn)
        // priority_queue<int> q(nums.begin(), nums.end());
        // int ret;
        // while(k){
        //     ret = q.top();
        //     q.pop();
        //     k--;
        // }
        // return ret;

        // option 3
        // Quick sort

        int left = 0, right = nums.size() - 1;
        while (true)
        {
            int pos = Partition(nums, left, right);
            if (nums.size() - pos == k)
                return nums[pos];
            if (nums.size() - pos > k)
                left = pos + 1;
            else
                right = pos - 1;
        }
    }
    void swap(int &x, int &y)
    {
        int temp = x;
        x = y;
        y = temp;
    }
    int Partition(vector<int> &nums, int l, int r)
    {
        int pivot = nums[r];
        int i = l - 1;
        for (int j = l; j < r; ++j)
        {
            if (nums[j] < pivot)
            {
                // swap
                i++;
                swap(nums[j], nums[i]);
            }
        }
        i++;
        swap(nums[i], nums[r]);
        return i;
    }
};
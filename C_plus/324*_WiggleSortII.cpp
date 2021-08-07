class Solution
{
public:
    void wiggleSort(vector<int> &nums)
    {
        // option 1 O(NlogN) time and O(N) space
        // 1. copy a vector 2. sorted this vector
        // 3. 從中間切兩半，兩個索引分別指向左半部(小數字)及右半部(大數字部分)
        // 4. 利用索引奇偶數 去 判斷拿 左半部還是右半部

        vector<int> vec = nums;
        sort(vec.begin(), vec.end());
        int n = nums.size();
        int small = (n - 1) / 2, large = n - 1;
        for (int i = 0; i < n; ++i)
        {
            if (i % 2 == 0)
            {
                // pick small
                nums[i] = vec[s--];
            }
            else
            {
                // pick large
                nums[i] = vec[l--];
            }
        }
    }
};
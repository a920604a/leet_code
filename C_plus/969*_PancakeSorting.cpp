class Solution
{
public:
    vector<int> ret;
    void sort(vector<int> &arr, int n)
    {

        // base case
        if (n == 1)
            return;

        // 在陣列中前n個元素中挑出最大值及其索引
        int maxCake = 0;
        int maxCakeIndex = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > maxCake)
            {
                maxCake = arr[i];
                maxCakeIndex = i;
            }
        }

        // 第一次翻轉，將最大餅翻到最上面
        reverse(arr.begin(), arr.begin() + maxCakeIndex + 1);
        // 第二次翻轉，將最大餅翻到做下面
        ret.push_back(maxCakeIndex + 1);
        reverse(arr.begin(), arr.begin() + maxCake);
        ret.push_back(n);

        sort(arr, n - 1);
    }
    vector<int> pancakeSort(vector<int> &arr)
    {
        // vector<int> nums = arr;
        // sort(nums.begin(), nums.end());
        // if(nums == arr) return {};
        // option 1 O(n^2)
        // recursive
        sort(arr, arr.size());
        return ret;

        // iteratively
        int n = arr.size();
        for (int i = n; i >= 1; --i)
        {
            if (i == 1)
                continue;
            int idx = 0, val = 0;
            for (int k = 0; k < i; ++k)
            {
                if (arr[k] > val)
                {
                    val = arr[k];
                    idx = k;
                }
            }

            reverse(arr.begin(), arr.begin() + idx + 1);
            reverse(arr.begin(), arr.begin() + i);
            ret.push_back(idx + 1);
            ret.push_back(i);
        }
        return ret;
    }
};
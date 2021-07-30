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

        // iterative
        //         vector<int> ret;
        //         int x,i;
        //         for( x = arr.size() ;x>0 ; x--){
        //             for(i=0; arr[i]!= x ; ++i) ;
        //             reverse(arr.begin(), arr.begin() + 1+i);
        //             ret.push_back(  i+1);
        //             reverse(arr.begin(), arr.begin() + x);
        //             ret.push_back(x);

        //         }
        //         return ret;
    }
};
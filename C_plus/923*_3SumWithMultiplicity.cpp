class Solution
{
public:
    int threeSumMulti(vector<int> &arr, int target)
    {

        // option 1 brute force
        // int mod = 1e+9+7;
        // int cnt = 0;
        // int n = arr.size();
        // for(int i=0;i<n-2;++i){
        //     for(int j=i+1;j<n;++j){
        //         for(int k=j+1;k<n;++k) cnt += (arr[i]+arr[j]+arr[k]==target)%mod;
        //     }
        // }
        // return cnt;

        int mod = 1e+9 + 7;
        long cnt = 0;
        int n = arr.size();
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n - 1; ++i)
        {
            int j = i + 1, k = n - 1;
            while (j < k)
            {
                int sum = arr[i] + arr[j] + arr[k];
                if (sum == target)
                {
                    int left = 1, right = 1;

                    while (j + left <= k && arr[j] == arr[j + left])
                        left++;
                    while (j + left <= k - right && arr[k] == arr[k - right])
                        right++;
                    if (arr[j] == arr[k])
                        cnt += (k - j + 1) * (k - j) / 2;
                    else
                        cnt += left * right;
                    j += left;
                    k -= right;
                }
                else if (sum < target)
                    j++;
                else
                    k--;
            }
        }
        return cnt % mod;
    }
};
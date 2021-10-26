class Solution
{
public:
    int threeSumMulti(vector<int> &arr, int target)
    {
        // two point O(n^2) time and O(1) space
        int cnt = 0;
        int mod = 1e+9 + 7;
        int n = arr.size();
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n - 2; ++i)
        {
            int l = i + 1, r = n - 1;
            while (l < r)
            {
                int sum = arr[i] + arr[l] + arr[r];
                if (sum == target)
                {
                    int left = 1, right = 1;
                    while (l + left <= r && arr[l + left] == arr[l])
                        left++;
                    while (l + left <= r - right && arr[r - right] == arr[r])
                        right++;
                    if (arr[l] == arr[r])
                        cnt += (r - l + 1) * (r - l) / 2;
                    else
                        cnt += left * right;
                    cnt = cnt % mod;
                    l += left;
                    r -= right;
                }
                else if (sum < target)
                    l++;
                else
                    r--;
            }
        }

        return cnt;
    }
};
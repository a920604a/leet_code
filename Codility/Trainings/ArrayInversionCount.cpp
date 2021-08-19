// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> merge(vector<int> &left, vector<int> &right, int &ans)
{
    vector<int> ret(left.size() + right.size(), 0);
    int l = 0, r = 0, k = 0;
    int count = 0;
    while (l < (int)left.size() && r < (int)right.size())
    {
        if (left[l] <= right[r])
        {
            ret[k++] = left[l++];
            ans += count;
        }
        else
        {
            ret[k++] = right[r++];
            count++;
        }
    }
    while (l < (int)left.size())
    {
        ret[k++] = left[l++];
        ans += count;
    }
    while (r < (int)right.size())
    {
        ret[k++] = right[r++];
    }
    return ret;
}
vector<int> mergeSort(vector<int> &a, int l, int r, int &ans)
{
    if (l == r)
        return {0};
    if (r - l == 1)
        return {a[l]};

    vector<int> left = mergeSort(a, l, (l + r) / 2, ans);
    vector<int> right = mergeSort(a, (l + r) / 2, r, ans);
    return merge(left, right, ans);
}
int solution(vector<int> &A)
{
    // write your code in C++14 (g++ 6.2.0)

    // O(n^2) timeout
    //  -1  6   3   4   7   4
    //   0  3   0   0   1   0

    // [1 2 3] => 0
    // [] => 0
    // dp[i] > dp[j] , dp[i] = dp[j
    // base case
    // if(A.empty() || A.size()==1) return 0;
    // int n = A.size();
    // vector<int> dp(n,0);
    // int ret = 0;
    // for(int i=n-2;i>-1;i--){
    //     for(int j = i+1;j<n;++j){
    //         if(A[i] > A[j]){
    //             dp[i] += +1 ;

    //             if(dp[i]> 1e+9) return -1;
    //         }
    //     }
    //     ret += dp[i];
    // }
    // return ret;

    // option 2 O(nlogn) merge sort
    // base case
    // if(A.empty() || A.size()==1) return 0;
    // int n = A.size();

    //        -1  6   3   4   7   4

    int ans = 0;
    mergeSort(A, 0, A.size(), ans);
    if (ans > 1e+9)
        return -1;
    return ans;
}

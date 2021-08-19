// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

bool isValid(string &l, string &r)
{
    int i = 0, j = l.size() - 1;
    while (i < j)
    {
        swap(l[i], l[j]);
        i++;
        j--;
    }
    return l == r;
}
int solution(string &S)
{
    // write your code in C++14 (g++ 6.2.0)
    // option 1 O(n^2) time out
    // if (S.empty())
    //     return 0;
    // if (S.size() == 1)
    //     return 0;
    // if (S.size() == 2)
    //     return 0;
    // //  racecar
    // // [i,n-1] 是否為回文
    // int ans = 2e+6, n = S.size();
    // for (int i = 1; i < n - 1; ++i)
    // {
    //     string left = S.substr(0, i);
    //     string right = S.substr(i + 1, (n - 1) - (i + 1) + 1);

    //     if (isValid(left, right))
    //     {
    //         ans = min(ans, i);
    //     }
    // }
    // return ans;

    // option 2 O(sqrt(n)) time

    if (S.empty())
        return -1;
    
    int n = S.size();
    if (n % 2 == 0)
    // 發生在長度為奇數
        return -1;
    int ans = n / 2;

    for (int i = ans, j = ans; j > -1 && i < n; i++, j--)
    {
        if (S[i] != S[j])
            return -1;
    }
    return ans;
}
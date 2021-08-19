// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <bits/stdc++.h>
vector<int> solution(string &S, vector<int> &P, vector<int> &Q)
{
    // write your code in C++14 (g++ 6.2.0)

    // brute force O(n^2) => time out
    //  2   1   3   2   2   4   1
    //
    //
    vector<int> ret;
    unordered_map<char, int> mp;
    string dna = "ACGT";
    int n = P.size();
    for (int i = 0; i < dna.size(); ++i)
        mp[dna[i]] = i + 1;
    for (int i = 0; i < n; ++i)
    {

        int temp = INT_MAX;
        int s = P[i], e = Q[i];
        for (int j = s; j <= e; ++j)
        {
            char d = S[j];
            temp = min(temp, mp[d]);
        }
        ret.push_back(temp);
    }
    return ret;
}

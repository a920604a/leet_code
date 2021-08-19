// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(string &E, string &L)
{
    // write your code in C++14 (g++ 6.2.0)
    int cost = 5;
    // 未滿一小時
    if (E[0] == L[0] && E[1] == L[1])
        return cost;

    //

    int ehour = 10 * (E[0] - '0') + (E[1] - '0');
    int lhour = 10 * (L[0] - '0') + (L[1] - '0');
    int hour = (lhour - ehour + 24) % 24;
    // cout<<hour<<endl;

    int emin = 10 * (E[3] - '0') + (E[4] - '0');
    int lmin = 10 * (L[3] - '0') + (L[4] - '0');
    int mins = lmin - emin;
    // cout<<mins<<endl;
    if (mins > 0)
        return cost + hour * 4;
    return cost + (hour - 1) * 4;
}

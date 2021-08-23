// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A)
{
    // write your code in C++14 (g++ 6.2.0)

    // int n = A.size();

    //  10  -10 -1  -1  10
    //  10  0   -1  -2  10
    //  10  0   -1
    // revisit
    //  10  0   -1  -1  10
    //  10  10  9   8   18

    //  -1  -1  -1  1   1   1   1
    //  0   0   0   1   2   3   4
    //

    //  5   -2  -3  1
    //  5   3   0   1

    // 假設陣列總和非負，代表解必定存在
    // 移動多少次收支可以讓公司不會負債
    // 確保當前總和為大於等於0
    // 一開始遇到負數肯定負債
    // 每次遇到當前總和為負數時，將先前最小負數位置補零，移動次數加一，並重新拜訪

    // O(n^2 ) maybe timeout

    // 確保當前總和為大於等於0
    if (A.size() == 1)
        return 0;
    int count = 0;
    vector<int> arr = A;
    int total = 0;
    for (int a : arr)
    {
        total += a;
        if (total < 0)
            break;
    }
    if (total == 0)
        return 0;

    while (total < 0)
    {
        int curmin = 0;
        int idxmin = -1;
        int sum = 0;
        for (int i = 0; i < (int)arr.size(); ++i)
        {
            if (arr[i] < curmin)
            {
                curmin = arr[i];
                idxmin = i;
            }
            sum += arr[i];
            if (sum < 0)
            {
                sum -= arr[i];
                arr[idxmin] = 0;
                count++;
                break;
            }
        }
        total = 0;
        for (int a : arr)
        {
            total += a;
            if (total < 0)
                break;
        }
    }
    return count;
}

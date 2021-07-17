class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        // AAABBB
        // A--A--A
        // AB-AB-AB
        // 計算字母出現次數最多為多少次 mx 3
        // 可以分為多少塊 mx-1 2
        // 每塊長度 A-- ： n+1 3
        // 需要補idle的個數 25-i，出現最多次字母個數
        // 可以分為多少塊* 每塊長度 + 25-i

        int size = tasks.size();
        vector<int> vec(26, 0);
        // 計算字母出現次數最多為多少次 mx
        for (char c : tasks)
            vec[c - 'A']++;
        sort(vec.begin(), vec.end());
        int mx = vec[25];

        int i = 25;
        while (i > 0 && vec[i] == mx)
            i--;
        cout << i << endl;
        return max(size, (mx - 1) * (n + 1) + 25 - i);
    }
};
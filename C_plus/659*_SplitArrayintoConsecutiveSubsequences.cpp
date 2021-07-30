class Solution
{
public:
    bool isPossible(vector<int> &nums)
    {
        if (nums.size() < 3)
            return false;

        // hash table freq 紀錄每個元素出現的次數，以幫助一個元素判斷自己是作為開頭，
        // hash table need 紀錄乃些元素可以被接到提他子序列後面，幫助一個元素判斷自己是否可以被接到其他序列後面
        unordered_map<int, int> freq, need;
        for (int n : nums)
            freq[n]++;

        for (int n : nums)
        {
            if (freq[n] == 0)
                continue;

            // 先判断 n 是否能接到其他子序列后面
            if (need.count(n) && need[n] > 0)
            {
                // n 可以接到之前的某个序列后面
                freq[n]--;
                // 对 n 的需求减一
                need[n]--;
                // 对 n + 1 的需求加一
                need[n + 1]++;
            }
            else if (freq[n] > 0 && freq[n + 1] > 0 && freq[n + 2] > 0)
            {
                // 将 n 作为开头，新建一个长度为 3 的子序列 [n,n+1,n+2]
                freq[n]--;
                freq[n + 1]--;
                freq[n + 2]--;
                // 对 n + 3 的需求加一
                need[n + 3]++;
            }
            else
            {
                // 两种情况都不符合，则无法分配
                return false;
            }
        }

        return true;
    }
};
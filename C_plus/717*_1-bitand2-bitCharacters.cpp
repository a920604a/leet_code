class Solution
{
public:
    bool isOneBitCharacter(vector<int> &bits)
    {
        // 兩種字符 第一種2-bit characters : 11 10，第二種1-bit character 0
        // 是否可以分割成 以1-bit結尾的

        int n = bits.size(), i = 0;
        while (i < n - 1)
        {
            if (bits[i] == 0)
                i++;
            else
                i += 2;
        }
        return i == n - 1;
    }
};
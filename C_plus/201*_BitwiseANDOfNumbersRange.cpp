class Solution
{
public:
    int rangeBitwiseAnd(int left, int right)
    {
        // option 1
        int count = 0;
        while (right != left)
        {
            right >>= 1;
            left >>= 1;
            count++;
        }
        return right << count;
    }
};
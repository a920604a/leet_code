class Solution
{
public:
    int findComplement(int num)
    {

        int ret = 0;
        unsigned mask = ~0;

        while (mask & num)
            mask <<= 1;
        return ~mask & ~num;
    }
};
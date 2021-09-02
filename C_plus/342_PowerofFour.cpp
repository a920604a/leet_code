class Solution
{
public:
    bool isPowerOfFour(int n)
    {

        // option 1
        // if(n<1) return false;
        // while(n%4==0){
        //     n /=4;
        // }
        // return n==1;

        // option 2 without loops/recursion
        // (0x55555555) <==> 1010101010101010101010101010101
        if (n < 1)
            return false;
        if ((n & (n - 1)) != 0)
            return false;
        return (n & 0x55555555) == n;
    }
};
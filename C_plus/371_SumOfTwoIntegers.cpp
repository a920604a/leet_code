class Solution
{
public:
    int getSum(int a, int b)
    {
        // option 1 , sum == ^ & operation
        // recurrent version
        // if(b==0) return a;
        // int sum = a^b;
        // int carry = (a&b& 0x7fffffff)<<1;
        // // 0x7fffffff = 2147483647
        // return getSum(sum, carry);

        // option 1  simplify one-line
        return b == 0 ? a : getSum(a ^ b, (a & b & 0x7fffffff) << 1);

        // option 2
        // int sum, carry;
        // while(b){
        //     sum = a^b;
        //     carry = (a&b& 0x7fffffff)<<1;
        //     a=sum;
        //     b= carry;
        // }
        // return a;

        // option 2 simplify
        int carry;
        while (b)
        {
            carry = (a & b & 0x7fffffff) << 1;
            a = a ^ b;
            b = carry;
        }
        return a;
    }
};
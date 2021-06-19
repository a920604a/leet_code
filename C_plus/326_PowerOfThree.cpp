class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        // option 1
        //  loop
        // if(n<1) return false;
        // while(n%3==0) n/=3;
        // return n==1;

        // option 2
        // without loops/recursion
        // tricky 3^19=1162261467 ,任何只要是3的指數一定能被他整除。
        // return (n>0 && 1162261467%n==0);

        // option 3
        // 換底公式 + a-int(a)==0
        return (n > 0 && (int(log10(n) / log10(3)) - (log10(n) / log10(3)) == 0));
    }
};
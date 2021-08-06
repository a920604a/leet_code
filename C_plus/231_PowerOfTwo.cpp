class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        // option 1  brute force
        // use loop
        // if(n<=0) return false;
        // else if(n>0){
        //     for(int i=2; i<n;i*=2){
        //         if(n/i%2==1) return false;
        //     }
        //     return true;
        // }
        // return true;

        // option 2
        // if(n<1) return false;
        // while(n%2==0) n/=2;
        // return n==1;

        //option 3 因為2的指數二進位 只會有一個1 的關係
        // bit-wise
        // int ret = 0 ;
        // if(n<=0) return false;
        // while(n){
        //    ret += (n&1);
        //    n >>=1;
        // }
        // return ret==1;

        //option 3.1 因為2的指數二進位 只會有一個1 的關係
        // bit-wise
        // int ret = 0 ;
        // if(n<=0) return false;
        // while(n){
        //    ret++;
        //    n = n &(n-1);
        // }
        // return ret==1;

        //option 4
        // make use of n&(n-1) 因為2的指數二進位 只會有一個1 的關係
        // 注意括號的優先級
        // if(n<=0) return false;
        // return (n&(n-1)) == 0;

        // return (n>0) && (!((n-1)&n));

        // option 5
        // tricky , 2^30 = 2147483648/2 = 1073741824
        // cout<<pow(2,30);
        // return pow(2,30)%n==0;
        return (n > 0) && (1073741824 % n == 0);
    }
};
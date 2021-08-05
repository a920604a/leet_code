class Solution
{
public:
    double myPow(double x, int n)
    {
        // brute force
        // if(n==0) return 1;
        // double ret = 1;
        // for (int i = 1; i <= abs(n); i++) {
        //     // 這裡有乘法，可能overflow
        //     ret *= x;
        // }
        // return n<0?1/ret:ret;

        // option 1 recursive
        // 如果 n 是偶數，返回myPow(x, n/2)*myPow(x, n/2)即可
        // 如果 n 是奇數，還要注意是否為負數，如果不是負數只要再乘上x即可。
        // 如果 n 是奇數，還要注意是否為負數，如果是負數只要再乘上x的倒數。但可能會溢位，所以延後判斷。
        
        // if(n==0) return 1;
        // double half = myPow(x, n/2);
        // if(n%2==0) return half*half;
        // if(n<0) return half*half/x;
        // else return half*half*x;

        // option 2 iterative

        // if(n==0) return 1;
        // double ret = 1.0;
        // for(int i=n;i!=0;i/=2){
        //     if(i%2!=0) ret*=x;
        //     x *=x;
        // }
        // return n<0?1/ret:ret;
    }
};
class Solution:
    def isPowerOfTwo(self, n: int) -> bool:

        # option 1
        if n == 0:
            return False
        while n % 2 == 0:
            n >>= 1
        return n == 1

        # option 2
        # if n==0:
        #     return False
        # return (n&(n-1))==0

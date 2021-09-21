class Solution:
    def climbStairs(self, n: int) -> int:
        # n = 1 -> 1
        # n = 2 -> 2
        # n = 3 -> 3 == 1+1+1 1+2 2+1
        # n = 4 -> 5 == 1+1+1+1 1+1+2 1+2+1 2+1+1 2+2
        
        a , b, c = 1,2,3
        if(n<3): return n
        
        for i in range(3,n+1):
            c = a+b
            a = b
            b = c
            
            
        return c
       
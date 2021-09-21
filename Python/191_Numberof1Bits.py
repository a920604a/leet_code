class Solution:
    def hammingWeight(self, n: int) -> int:
        # option 1
        ret = 0
        while n:
            ret += 1
            n = n & (n - 1)
        return ret

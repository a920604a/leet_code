class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        # option 1 O(nlogn) time
        ret = 0
        l = list()
        for i in nums:
            l.append(i)

        l.sort()
        for i in l:
            if i == ret + 1:
                ret += 1

        return ret + 1

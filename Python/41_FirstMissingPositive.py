"""
Author: yuan
Date: 2021-07-14 21:27:37
LastEditTime: 2021-07-14 21:27:38
FilePath: /leet_code/Python/41_FirstMissingPositive.py
"""


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

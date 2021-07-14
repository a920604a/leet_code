"""
Author: yuan
Date: 2021-07-14 21:13:38
LastEditTime: 2021-07-14 21:13:47
FilePath: /leet_code/Python/5_LongestPalindromicSubstring.py
"""
"""
Author: yuan
Date: 2021-07-14 21:13:38
LastEditTime: 2021-07-14 21:13:39
FilePath: /leet_code/Python/5_LongestPalindromicSubstring.py
"""


class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        i = 0
        maxlen = 0
        while i < n:
            j = i
            k = i
            while k < n - 1 and s[k + 1] == s[k]:
                k += 1
            i = k + 1
            while j > 0 and k < n - 1 and s[j - 1] == s[k + 1]:
                j -= 1
                k += 1
            if maxlen < k - j + 1:
                maxlen = k - j + 1
                start = j

        return s[start : start + maxlen]

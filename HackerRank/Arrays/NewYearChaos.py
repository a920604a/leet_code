'''
Author: yuan
Date: 2021-07-15 20:35:22
LastEditTime: 2021-07-15 20:35:31
FilePath: /leet_code/HackerRank/Arrays/NewYearChaos.py
'''
"""
Author: yuan
Date: 2021-07-15 20:35:22
LastEditTime: 2021-07-15 20:35:23
FilePath: /leet_code/HackerRank/Arrays/NewYearChaos.py
"""
#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'minimumBribes' function below.
#
# The function accepts INTEGER_ARRAY q as parameter.
#


def minimumBribes(q):
    # Write your code here
    ret = 0
    for i in range(len(q) - 1, -1, -1):
        expectedVal = i + 1
        if q[i] == expectedVal:
            continue
        elif q[i - 1] == expectedVal:
            ret += 1
            # swap i , i-1
            q[i], q[i - 1] = q[i - 1], q[i]
        elif q[i - 2] == expectedVal:
            ret += 2
            # swap i-2 i-1
            q[i - 1], q[i - 2] = q[i - 2], q[i - 1]
            # swap i-1 i
            q[i - 1], q[i] = q[i], q[i - 1]
        else:
            return "Too chaotic"

    return ret


if __name__ == "__main__":
    t = int(input().strip())

    for t_itr in range(t):
        n = int(input().strip())

        q = list(map(int, input().rstrip().split()))

        print(minimumBribes(q))

# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")


def solution(A):
    # write your code in Python 3.6
    # O(n) or O(NlogN) time and O(n) space
    n = len(A)
    sum = []
    sum.append(A[n - 1])
    for i in range(n - 2, -1, -1):
        # suminsert(0, sum[0]+A[i]) # O(n)
        sum.append(sum[-1] + A[i])
    # reverse
    sum = sum[::-1]
    # 13    10  9   7   3
    ret = 1e5
    total = 0
    for i in range(n - 1):
        total += A[i]
        ret = min(abs(total - sum[i + 1]), ret)
    return ret

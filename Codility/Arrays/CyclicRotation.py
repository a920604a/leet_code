# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")


def solution(A, K):
    # write your code in Python 3.6
    # O(n) space and O(n) time
    if not A:
        return []
    size = len(A)

    k = K % size
    ret = []
    for i in range(size):
        ret.append(A[(size - k + i) % size])

    return ret

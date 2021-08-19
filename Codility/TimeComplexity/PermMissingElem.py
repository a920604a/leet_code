# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")


def solution(A):
    # write your code in Python 3.6
    n = len(A)
    total = (n + 2) * (n + 1) / 2
    for i in A:
        total -= i
    return int(total)


def solution(A):
    # write your code in Python 3.6
    ret = len(A)

    for i in range(len(A)):
        ret = ret ^ i ^ (A[i] - 1)

    return ret + 1

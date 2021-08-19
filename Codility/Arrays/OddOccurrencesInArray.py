# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")


def solution(A):
    # write your code in Python 3.6
    ret = 0
    for i in A:
        ret = ret ^ i
    return ret

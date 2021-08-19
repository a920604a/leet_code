# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")


def solution(N):
    # write your code in Python 3.6
    # O(n) time and O(n) space
    # 9  1001 => 2
    # 15 1111 => 0
    # 32 100000 => 0
    # 1041 10000010001 => 5
    
    # to string
    l = []
    while N:
        l.append(N & 1)
        N >>= 1

    l = l[::-1]

    ret = 0
    c = 0
    flag = False
    for i in l:
        if i == 0:
            c += 1
        elif i == 1:
            if flag:
                ret = max(ret, c)
                c = 0
            flag = True

    return ret

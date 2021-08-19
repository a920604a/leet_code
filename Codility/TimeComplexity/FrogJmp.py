# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(X, Y, D):
    # write your code in Python 3.6
    if (Y-X)%D==0 :
        return int((Y-X)/D)
    else:
        return int((Y-X)/D +1)
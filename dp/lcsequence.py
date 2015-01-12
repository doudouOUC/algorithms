# -*- coding : utf-8 -*-
#
# File Name: lcs.py
# Author: jinye
# mail: jinye.djy@alibaba-inc.com
# Created Time: Tue Jan  6 11:15:02 2015


def max_3(a, b , c):
    if a > b:
        if a > c:
            return a
        else:
            return c
    elif b > c:
        return b
    else:
        return c

def LCS(str1, str2):
    len1 = len(str1)
    len2 = len(str2)
    d = [[0 for j in range(len2+1)]for i in range(len1+1)]
    for i in range(1, len1+1):
        for j in range(1, len2+1):
            last_max = max_3(d[i-1][j-1], d[i-1][j], d[i][j-1])
            if str1[i-1] == str2[j-1]:
                d[i][j] = d[i-1][j-1] +1
            else:
                d[i][j] = last_max
    print d[len1][len2]
    print_LCS(d, str1, str2)

def print_LCS(d, str1, str2):
    i = len(str1)
    j = len(str2)
    stack = ""
    while i > 0 and j > 0:
        if str1[i-1] == str2[j-1]:
            stack += str1[i-1]
            i -= 1
            j -= 1
        elif d[i-1][j] == d[i][j]:
            i -= 1
        elif d[i][j-1] == d[i][j]:
            j -= 1
    print stack[::-1]

if __name__ == "__main__":
    # qheq
    LCS("akqrshrengxqiyxuloqk", "tdzbujtlqhecaqgwfzbc")
    # BDAB
    LCS("BDCABA", "ABCBDAB")

# -*- coding : utf-8 -*-
#
# File Name: lcsubstring.py
# Author: jinye
# mail: jinye.djy@alibaba-inc.com
# Created Time: Tue Jan  6 15:36:32 2015

def LCS(str1, str2):
    len1 = len(str1)
    len2 = len(str2)
    max = 0
    max_i = 0
    max_j = 0
    d = [[0 for i in range(len2+1)] for j in range(len1+1)]
    for i in range(1, len1+1):
        for j in range(1, len2+1):
            if str1[i-1] == str2[j-1]:
                d[i][j] = d[i-1][j-1]+1
                if d[i][j] >= max: # change to > select first, now the last
                    max = d[i][j]
                    max_i = i
                    max_j = j
            else:
                d[i][j] = 0
    print max, max_i, max_j
    stack = ""
    while d[max_i][max_j] != 0:
        stack += str1[max_i-1]
        max_i -= 1
        max_j -= 1
    print stack[::-1]


if __name__ == "__main__":
    LCS("blog.iderzheng.com", "ider.cs@gmail.com")

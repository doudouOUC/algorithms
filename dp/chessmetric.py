# -*- coding : utf-8 -*-
#
# File Name: chessmetric.py
# Author: jinye
# mail: jinye.djy@alibaba-inc.com
# Created Time: Mon Jan  5 12:08:23 2015

import copy

class ChessMetric(object):
    def __init__(self):
        pass

    def cal_l_upper_left(self, i, j):
        if i-1 >= 0 and j+2 < self.size:
            return self.last_d[i-1][j+2]
        return 0

    def cal_l_upper_right(self, i, j):
        if i+1 < self.size and j+2 < self.size:
            return self.last_d[i+1][j+2]
        return 0

    def cal_l_left_upper(self, i, j):
        if i-2 >= 0 and j+1 < self.size:
            return self.last_d[i-2][j+1]
        return 0

    def cal_l_left_bottom(self, i, j):
        if i-2 >= 0 and j-1 >= 0:
            return self.last_d[i-2][j-1]
        return 0

    def cal_l_right_upper(self, i, j):
        if i+2 < self.size and j+1 < self.size:
            return self.last_d[i+2][j+1]
        return 0

    def cal_l_right_bottom(self, i, j):
        if i+2 < self.size and j-1 >= 0:
            return self.last_d[i+2][j-1]
        return 0

    def cal_l_bottom_left(self, i, j):
        if i+1 < self.size and j-2 >= 0:
            return self.last_d[i+1][j-2]
        return 0

    def cal_l_bottom_right(self, i, j):
        if i-1 >= 0 and j-2 >= 0:
            return self.last_d[i-1][j-2]
        return 0

    def cal_x_upper(self, i, j):
        if j+1 < self.size:
            return self.last_d[i][j+1]
        return 0

    def cal_x_bottom(self, i, j):
        if j-1 >= 0:
            return self.last_d[i][j-1]
        return 0

    def cal_x_left(self, i, j):
        if i-1 >= 0:
            return self.last_d[i-1][j]
        return 0

    def cal_x_right(self, i, j):
        if i+1 < self.size:
            return self.last_d[i+1][j]
        return 0

    def cal_x_left_upper(self, i, j):
        if i-1 >=0 and j+1 < self.size:
            return self.last_d[i-1][j+1]
        return 0

    def cal_x_left_bottom(self, i, j):
        if i-1 >=0 and j-1 >=0:
            return self.last_d[i-1][j-1]
        return 0

    def cal_x_right_upper(self, i, j):
        if i+1 < self.size and j+1 < self.size:
            return self.last_d[i+1][j+1]
        return 0

    def cal_x_right_bottom(self, i, j):
        if i+1 < self.size and j-1 > 0:
            return self.last_d[i+1][j-1]
        return 0

    def cal_l(self, i, j):
        temp = 0
        temp += self.cal_l_bottom_left(i, j) + self.cal_l_bottom_right(i, j)
        temp += self.cal_l_right_bottom(i, j) + self.cal_l_right_upper(i, j)
        temp += self.cal_l_left_bottom(i, j) + self.cal_l_left_upper(i, j)
        temp += self.cal_l_upper_left(i, j) + self.cal_l_upper_right(i, j)
        return temp

    def cal_x(self, i, j):
        temp = 0
        temp += self.cal_x_upper(i, j) + self.cal_x_bottom(i, j)
        temp += self.cal_x_left(i, j) + self.cal_x_right(i, j)
        temp += self.cal_x_left_upper(i, j) + self.cal_x_left_bottom(i, j)
        temp += self.cal_x_right_upper(i, j) + self.cal_x_right_bottom(i, j)
        return temp

    def how_many(self, size, start, finish, num_moves):
        self.size = size
        self.last_d = [[0 for j in range(size)] for i in range(size)]
        self.d = [[0 for j in range(size)] for i in range(size)]
        self.last_d[0][0] = 1
        for index in range(num_moves):
            for i in range(size):
                for j in range(size):
                    if index ==0 and i == 0 and j == 0:
                        continue
                    self.d[i][j] = self.cal_l(i, j) + self.cal_x(i, j)
            self.last_d = copy.deepcopy(self.d)
        print self.d[finish[0]][finish[1]]


if __name__ == "__main__":
    chess = ChessMetric()
    chess.how_many(3, (0, 0), (1, 0), 1)
    chess.how_many(3, (0, 0), (1, 2), 1)
    chess.how_many(3, (0, 0), (2, 2), 1)
    chess.how_many(3, (0, 0), (0, 0), 2)
    chess.how_many(100, (0, 0), (0, 99), 50)

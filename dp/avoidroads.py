# -*- coding : utf-8 -*-
#
# File Name: avoidroads.py
# Author: jinye
# mail: jinye.djy@alibaba-inc.com
# Created Time: Sun Jan  4 19:58:03 2015


class AvoidRoads(object):
    def __init__(self):
        pass

    def left_value(self, i, j):
        if i-1 >= 0 and not self.is_obstacle(i-1, j, i, j):
            return self.d[i-1][j]
        return 0

    def bottom_value(self, i, j):
        if j-1 >= 0 and not self.is_obstacle(i, j-1, i, j):
            return self.d[i][j-1]
        return 0

    def cal_ways(self, i, j):
        return self.left_value(i, j) + self.bottom_value(i, j)

    def is_obstacle(self, x1, y1, x2, y2):
        if (x1, y1, x2, y2) in self.obstacles or \
           (x2, y2, x1, y1) in self.obstacles:
            return True
        return False

    def set_obstacles(self, bad):
        self.obstacles = []
        for obstacle in bad:
            array = obstacle.split(" ")
            x1 = int(array[0])
            y1 = int(array[1])
            x2 = int(array[2])
            y2 = int(array[3])
            self.obstacles.append((x1, y1, x2, y2))

    def num_ways(self, width, height, bad):
        self.set_obstacles(bad)
        self.width = width
        self.height = height
        self.d = [[] for i in range(width+1)]
        for i in range(width+1):
            for j in range(height+1):
                self.d[i].append(1)
        for i in range(width+1):
            for j in range(height+1):
                if i == 0 and j == 0:
                    continue
                path = self.cal_ways(i, j)
                self.d[i][j] = path
        print self.d[width][height]


if __name__ == "__main__":
    roads = AvoidRoads()
    roads.num_ways(35, 31, "")
    roads.num_ways(1, 1, "")
    roads.num_ways(2, 2, ["0 0 1 0", "1 2 2 2", "1 1 2 1"])
    roads.num_ways(6, 6, ["0 0 0 1", "6 6 5 6"])

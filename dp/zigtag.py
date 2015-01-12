# -*- coding : utf-8 -*-
#
# File Name: zigtag.py
# Author: jinye
# mail: jinye.djy@alibaba-inc.com
# Created Time: Tue Dec 30 15:32:46 2014


class ZigZag(object):
    def __init__(self, src=[]):
        self.sequence = src
        self.state = range(len(src))

    def set_sequence(self, src):
        self.sequence = src
        self.d = range(len(src))
        self.state = range(len(src))
        for i in range(len(src)):
            self.d[i] = 0
            self.state[i] = 0

    def longestzigzag(self):
        if len(self.sequence) <= 2:
            print len(self.sequence)
            return
        self.d[0] = 1
        self.state[1] = self.sequence[1] - self.sequence[0]
        self.d[1] = 2
        max = self.d[1]
        for i in range(2, len(self.sequence)):
            for j in range(1, i):
                diff = self.sequence[i] - self.sequence[j]
                if self.state[j] * diff < 0:
                    temp = self.d[j] + 1
                    if self.d[i] < temp:
                        self.d[i] = temp
                        self.state[i] = diff
            if max < self.d[i]:
                max = self.d[i]
        print max


if __name__ == "__main__":
    zigzag = ZigZag()
    zigzag.set_sequence([1, 7, 4, 9, 2, 5])
    zigzag.longestzigzag()
    zigzag.set_sequence([1, 17, 5, 10, 13, 15, 10, 5, 16, 8])
    zigzag.longestzigzag()
    zigzag.set_sequence([44])
    zigzag.longestzigzag()
    zigzag.set_sequence([1, 2, 3, 4, 5, 6, 7, 8, 9])
    zigzag.longestzigzag()
    zigzag.set_sequence([70, 55, 13, 2, 99, 2, 80, 80, 80, 80, 100,
                         19, 7, 5, 5, 5, 1000, 32, 32])
    zigzag.longestzigzag()
    zigzag.set_sequence([374, 40, 854, 203, 203, 156, 362, 279, 812, 955,
                         600, 947, 978, 46, 100, 953, 670, 862, 568, 188,
                         67, 669, 810, 704, 52, 861, 49, 640, 370, 908,
                         477, 245, 413, 109, 659, 401, 483, 308, 609, 120,
                         249, 22, 176, 279, 23, 22, 617, 462, 459, 244])
    zigzag.longestzigzag()

# -*- coding : utf-8 -*-
#
# File Name: flowergarden.py
# Author: jinye
# mail: jinye.djy@alibaba-inc.com
# Created Time: Sun Jan  4 17:53:26 2015


class FlowerGarden(object):
    def __init__(self):
        pass

    def get_ordering(self, heights, blooms, wilts):
        pass

if __name__ == "__main__":
    garden = FlowerGarden()
    garden.get_ordering([5, 4, 3, 2, 1],
                        [1, 1, 1, 1, 1],
                        [365, 365, 365, 365, 365])
    garden.get_ordering([5, 4, 3, 2, 1],
                        [1, 5, 10, 15, 20],
                        [4, 9, 14, 19, 24])
    garden.get_ordering([5, 4, 3, 2, 1],
                        [1, 5, 10, 15, 20],
                        [5, 10, 15, 20, 25])
    garden.get_ordering([5, 4, 3, 2, 1],
                        [1, 5, 10, 15, 20],
                        [5, 10, 14, 20, 25])
    garden.get_ordering([1, 2, 3, 4, 5, 6],
                        [1, 3, 1, 3, 1, 3],
                        [2, 4, 2, 4, 2, 4])
    garden.get_ordering([3, 2, 5, 4],
                        [1, 2, 11, 10],
                        [4, 3, 12, 13])

from typing import *
from math import *

class Solution:
    def findSubsequences(self, nums: List[int]) -> List[List[int]]:
        answ = set()
        permutator = []

        def find(index, last):
            if index == len(nums):
                if len(permutator)>=2:
                    answ.add(tuple(permutator))
                return

            find(index + 1, last)
            
            if nums[index] >= last:
                permutator.append(nums[index])
                find(index + 1, nums[index])
                permutator.pop()

        find(0, -1000)
        return answ

print(Solution.findSubsequences(Solution, nums=list([4, 6, 7, 7])))

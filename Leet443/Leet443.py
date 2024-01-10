from typing import *
from math import *

class Solution:
    def compress(self, chars: List[str]) -> int:
        res = 0
        i = 0
        while i < len(chars):
            count = 1
            while i + count < len(chars) and chars[i + count] == chars[i]:
                count += 1
            chars[res] = chars[i]
            res += 1
            # print(chars)
            if count > 1:
                str_repr = str(count)
                chars[res:res+len(str_repr)] = list(str_repr)
                res += len(str_repr)
            # print(chars)
            i += count
        return res

unshrinked = ["a","a","a", "b","b","b","b", "a","a"]
length = Solution.compress(Solution, chars=unshrinked)

print(unshrinked[:length])
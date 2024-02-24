from typing import List
class Solution:
    def two_sum(self, nums: List[int], target: int) -> List[int]:

        num_dic = {}

        for i,n in enumerate(nums):
            if target - n in num_dic:
                return [num_dic[target-n],i]
            num_dic[n] = i

        return []


listx = [2,7,11,15]
target = 9

solution = Solution()
print(solution.two_sum(listx, target))

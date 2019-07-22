from typing import List

def two_sum(nums: List[int], target: int) -> List[int]:
    for i in range(len(nums) - 1):
        for j in range(len(nums)):
            if nums[i] + nums[j] == target:
                return [i, j]
    return []

print(two_sum([1,2,3,4], 4))
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        mp = {}

        for i in range(len(nums)):
            values = target - nums[i]
            if values in mp:
                return [mp[values], i]
            
            mp[nums[i]] = i

        return []
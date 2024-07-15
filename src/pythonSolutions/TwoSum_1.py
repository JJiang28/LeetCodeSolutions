class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        result = []
        myMap = {}
        for i in range(len(nums)):
            if nums[i] in myMap:
                result.append(myMap[nums[i]])
                result.append(i)
            myMap[target-nums[i]] = i
        return result
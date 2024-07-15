class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        a = set(nums)
        return not (len(a) == len(nums))
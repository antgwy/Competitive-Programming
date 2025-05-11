class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        
        def lower_bound(nums, target):
            l, r = 0, len(nums)
            while l < r:
                mid = (l + r) // 2
                if nums[mid] < target:
                    l = mid + 1
                else:
                    r = mid
            return l

        st = lower_bound(nums, target)
        if st == len(nums) or nums[st] != target:
            return [-1, -1]

        ed = lower_bound(nums, target + 1) - 1
        return [st, ed]
        
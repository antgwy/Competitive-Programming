class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        n = len(nums)
        mind = inf

        for i in range(n - 2):
            if i and nums[i] == nums[i-1]:
                continue

            # s = nums[i] + nums[i+1] + nums[i+2]
            # if s > target:
            #     if s - target < mind:
            #         ans = s
            #     break
            
            # s = nums[i] + nums[-2] + nums[-1]
            # if s < target:
            #     if target - s < mind:
            #         mind = target - s
            #         ans = s
            #     continue

            j, k = i + 1, n - 1
            while j < k:
                s = nums[i] + nums[j] + nums[k]
                if s == target:
                    return target

                if s > target:
                    if s - target < mind:
                        mind = s - target
                        ans = s
                    k -= 1
                else:
                    if target - s < mind:
                        mind = target - s
                        ans = s
                    j += 1
            
        return ans
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        q = collections.deque()
        for i in range(k):
            while q and nums[i] >= nums[q[-1]]:
                q.pop()
            q.append(i)

        ans = [nums[q[0]]]
        for i in range(k, n):
            while q and nums[i] >= nums[q[-1]]:
                q.pop()
            q.append(i)
            while q[0] <= i - k:
                q.popleft()
            ans.append(nums[q[0]])

        return ans

# class Solution:
#     def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
#         n = len(nums)
#         q = [(-nums[i], i) for i in range(k)]
#         heapq.heapify(q)

#         ans = [-q[0][0]]
#         for i in range(k, n):
#             heapq.heappush(q, (-nums[i], i))
#             while q[0][1] <= i - k:
#                 heapq.heappop(q)
#             ans.append(-q[0][0])
        
#         return ans
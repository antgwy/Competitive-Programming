class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        ans = []
        temp = []

        def dfs(cur: int) -> None:
            if len(temp) + (n - cur + 1) < k:
                return
            
            if len(temp) == k:
                ans.append(temp.copy())
                return

            temp.append(cur)
            dfs(cur + 1)
            temp.pop()
            dfs(cur + 1)

        dfs(1)

        return ans

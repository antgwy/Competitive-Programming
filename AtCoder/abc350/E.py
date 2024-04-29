from functools import lru_cache

n, a, x, y = map(int, input().split())

@lru_cache(None)
def dfs(n: int) -> float:
    if n == 0:
        return 0
    E1 = x + dfs(n//a)
    E2 = (6 * y + dfs(n//2) + dfs(n//3) + dfs(n//4) + dfs(n//5) + dfs(n//6))/5
    return min(E1, E2)

res = dfs(n)
print("%.8f" % res)
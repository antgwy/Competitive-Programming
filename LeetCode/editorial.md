
## [208. Implement Trie (Prefix Tree)](https://leetcode.cn/problems/implement-trie-prefix-tree/) (Medium)

题意：实现 Trie 类模板（含插入字符串，查找字符串和前缀）。

## [421. Maximum XOR of Two Numbers in an Array](https://leetcode.cn/problems/maximum-xor-of-two-numbers-in-an-array/) (Medium)

## [2935. Maximum Strong Pair XOR II](https://leetcode.cn/problems/maximum-strong-pair-xor-ii/) (Hard)

## [2940. Find Building Where Alice and Bob Can Meet](https://leetcode.cn/problems/find-building-where-alice-and-bob-can-meet/) (Hard)

## [2945. Find Maximum Non-decreasing Array Length](https://leetcode.cn/problems/find-maximum-non-decreasing-array-length/) (Hard)

## [2949. Count Beautiful Substrings II](https://leetcode.cn/problems/count-beautiful-substrings-ii/) (Hard)

## [2959. Number of Possible Sets of Closing Branches](https://leetcode.cn/problems/number-of-possible-sets-of-closing-branches/) (Hard)

&emsp;&emsp;状态压缩 floyd 暴力。

## [2963. Count the Number of Good Partitions](https://leetcode.cn/problems/count-the-number-of-good-partitions/) (Hard)

&emsp;&emsp;找出不可分割区间数目 $c$，答案为 $2^{c-1}$，维护每个元素最后出现位置。

## [2968. Apply Operations to Maximize Frequency Score](https://leetcode.cn/problems/apply-operations-to-maximize-frequency-score/)

题意：对数组加减 1 至多 $k$ 次使众数频率最大，求这个频率。

&emsp;&emsp;操作的数必定为排序后区间里的连续数，二分答案求滑动窗口的中位数判断。

## [3093. Longest Common Suffix Queries](https://leetcode.cn/problems/longest-common-suffix-queries/) (Hard)

题意：在 container 中找到与 query 有最长公共后缀的字符串。若有多个，选长度最短的，若一样选出现更早的。

&emsp;&emsp;倒序字符串插入字典树，每个节点更新 {len, id} 键值对，倒序查询求解。

## [3108. Minimum Cost Walk in Weighted Graph](https://leetcode.cn/problems/minimum-cost-walk-in-weighted-graph/) (Hard)

题意：带权无向图求路径与运算和最小值。

&emsp;&emsp;对于同一个联通块，与运算越多越小，允许经过重复边，最优解是连通块内所有边与运算，并查集或 DFS 实现。

## [3116. Kth Smallest Amount With Single Denomination Combination](https://leetcode.cn/problems/kth-smallest-amount-with-single-denomination-combination/) (Hard)

题意：使用无限量不同面额硬币组合（不能组合不同面额），求得到的第 $k$ 小金额。

&emsp;&emsp;答案具有单调性，问题转化为可组合多少不超过 $m$ 的金额，容斥原理计数，如两种 $x$ 和 $y$ 组合出 $\lfloor\frac{m}{x}\rfloor+\lfloor\frac{m}{y}\rfloor-\lfloor\frac{m}{LCM(x,y)}\rfloor$ 个，然后二分答案。

## [3117. Minimum Sum of Values by Dividing Array](https://leetcode.cn/problems/minimum-sum-of-values-by-dividing-array) (Hard)

题意：两个数组 nums(n) 和 andValues(m)，划分 nums 为 $m$ 个不相交连续子数组，子数组与和等于 andValues，求最小子数组值的和（值为数组最后一个元素）。

&emsp;&emsp;记忆 DP，dfs(i, j, andv) 表示到 nums[i] 划分了 j 段，参与划分结果为 andv。

## [3123. Find Edges in Shortest Paths](https://leetcode.cn/problems/find-edges-in-shortest-paths/) (Hard)

题意：$n$ 个节点 $m$ 条边的无向带权图，返回每条边是否在某条 $0$ 到 $n-1$ 是最短路上的 boolean 数组。

&emsp;&emsp;两遍 dijkstra 判断每条边能否达到最短路，也可以一遍 dijkstra+DFS/BFS 优化一下。

## [3134. Find the Median of the Uniqueness Array](https://leetcode.cn/problems/find-the-median-of-the-uniqueness-array/) (Hard)

题意：将数组所有子数组不同元素个数作为新元素组成新数组，求中位数。

&emsp;&emsp;$\frac{n(n+1)}{2}$ 个子数组，答案具有单调性，二分答案滑动窗口判断。

## [3149. Find the Minimum Cost Array Permutation](https://leetcode.cn/problems/find-the-minimum-cost-array-permutation/) (Hard)

题意：数组 a 和 p 是一个 $[0,\cdots,n-1]$ 排列，对于任意 p，求 $\displaystyle\min\sum_{i=0}^{n-1}|p[i]-a[p[(i+1)\%n]]|$。

&emsp;&emsp;目标具有旋转不变性，逆向递推同时记录每个状态填的数，$dp[mask][i]=\min(dp[mask|2^j][j] + abs(i-a[j]))$，0 必然是第一个，每次递推含 0 则 mask 必为奇数。

## [3154. Find Number of Ways to Reach the K-th Stair](https://leetcode.cn/problems/find-number-of-ways-to-reach-the-k-th-stair/) (Hard)

题意：每次走 -1（不能连续用）或 $i+2^j$（用后 j++），求从 1 到位置 k 的方案数。

&emsp;&emsp;第二种操作 $i$ 次，考虑可能位置有 $(2^i-1)-(i+1)\le k-1\le(2^i-1)$，将第一次操作插入第二次中，插空法 $\sum_iC_{i+1}^{2^i-k}$， $O(\log k)$ 。也可以记忆化 DP。

## [3165. Maximum Sum of Subsequence With Non-adjacent Elements](https://leetcode.cn/problems/maximum-sum-of-subsequence-with-non-adjacent-elements/) (Hard)

题意：单点修改，查询不包含相邻元素子序列最大和。

&emsp;&emsp;线段树优化下 DP，需要记录的信息是第一个和最后一个数选不选。

## [LCR 170. 交易逆序对的总数](https://leetcode.cn/problems/shu-zu-zhong-de-ni-xu-dui-lcof/) (Hard)
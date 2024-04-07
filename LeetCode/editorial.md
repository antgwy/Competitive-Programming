
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

## [LCR 170. 交易逆序对的总数](https://leetcode.cn/problems/shu-zu-zhong-de-ni-xu-dui-lcof/) (Hard)
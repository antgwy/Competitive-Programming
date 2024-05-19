
# 字符串

## Manacher

## KMP

* z 函数 (后缀与该字符串 LCP 长度, $O(n)$)

```cpp
vector<int> zfunc(string s) {
    int n = s.size();
    vector<int> z(n + 1);
    z[0] = n;
    for (int i = 1, j = 1; i < n; i++) {
        z[i] = max(0, min(j + z[j] - i, z[i-j]));
        while (i + z[i] < n && s[z[i]] == s[i+z[i]]) {
            z[i]++;
        }
        if (i + z[i] > j + z[j]) j = i;
    }
    return z;
}
```


## Trie

[173div2 E.](https://codeforces.com/contest/282/submission/203629344)

[367div2 D.](https://codeforces.com/contest/706/submission/197463847)

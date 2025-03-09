
# 字符串

## 哈希

* 双模哈希

```cpp
const int B[] = {131, 13331};
const int P[] = {998244353, 1000000007};
const int C = 2;
struct Hash {
    vector<int> h[C], pw[C];
    Hash() {}
    Hash(string s) {
        int n = s.size();
        init(s, n);
    }
    void init(string s, int n) {
        for (int i = 0; i < C; i++) {
            h[i].resize(n + 1);
            pw[i].resize(n + 1);
            h[i][0] = 1; pw[i][0] = 1;
        }
        for (int i = 0; i < C; i++) {
            for (int j = 1; j <= n; j++) {
                h[i][j] = (1ll * h[i][j-1] * B[i] + s[j-1]) % P[i];
                pw[i][j] = 1ll * pw[i][j-1] * B[i] % P[i];
            }
        }
    }
    auto get(int l, int r) {
        array<int, C> v{};
        if (l > r) return v;
        for (int i = 0; i < C; i++) {
            v[i] = (h[i][r] - 1ll * h[i][l-1] * pw[i][r-l+1]) % P[i];
            if (v[i] < 0) v[i] += P[i];
        }
        return v;
    }
    auto get(int l, int r, int d) {
        auto v = get(l, r);
        if (l > r) return v;
        for (int i = 0; i < C; i++) v[i] = 1ll * v[i] * pw[i][d] % P[i];
        return v;
    }
};
```

## Manacher

```cpp
vector<int> manacher(string s) {
    string t = "#";
    for (auto c : s) {
        t += c;
        t += '#';
    }
    int n = t.size();
    vector<int> r(n);
    for (int i = 1, j = 0; i < n; i++) {
        if (2 * j - i >= 0 && j + r[j] > i) {
            r[i] = min(r[2*j-i], j + r[j] - i);
        }
        while (i >= r[i] && i + r[i] < n && t[i-r[i]] == t[i+r[i]]) {
            r[i] += 1;
        }
        if (i + r[i] > j + r[j]) j = i;
    }
    return r;
}
```

## KMP

```cpp
vector<int> kmp(string s) {
    int n = s.size();
    vector<int> f(n + 1);
    for (int i = 1, j = 0; i < n; i++) {
        while (j && s[i] != s[j]) j = f[j];
        j += (s[i] == s[j]);
        f[i+1] = j;
    }
    return f;
}
```


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

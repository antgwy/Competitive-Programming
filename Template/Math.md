
# 数学

## 取模数

```cpp
constexpr int P = 998244353;

int norm(int x) {
    if (x < 0) x += P;
    if (x >= P) x -= P;
    return x;
}
template<class T> T qpow(T a, ll b) {
    T res = 1;
    for (; b; b /= 2, a *= a)
        if (b % 2) res *= a;
    return res;
}
struct Z {
    int x;
    Z(int x = 0) : x(norm(x)) {}
    Z(ll x) : x(norm(x % P)) {}
    int val() const {
        return x;
    }
    Z operator-() const {
        return Z(norm(P - x));
    }
    Z inv() const {
        assert(x != 0);
        return qpow(*this, P - 2);
    }
    Z &operator*=(const Z &rhs) {
        x = ll(x) * rhs.x % P;
        return *this;
    }
    Z &operator+=(const Z &rhs) {
        x = norm(x + rhs.x);
        return *this;
    }
    Z &operator-=(const Z &rhs) {
        x = norm(x - rhs.x);
        return *this;
    }
    Z &operator/=(const Z &rhs) {
        return *this *= rhs.inv();
    }
    friend Z operator*(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res *= rhs;
        return res;
    }
    friend Z operator+(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res += rhs;
        return res;
    }
    friend Z operator-(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res -= rhs;
        return res;
    }
    friend Z operator/(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res /= rhs;
        return res;
    }
    friend std::istream &operator>>(std::istream &is, Z &a) {
        ll v;
        is >> v;
        a = Z(v);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const Z &a) {
        return os << a.val();
    }
    friend bool operator==(Z lhs, Z rhs) {
        return lhs.val() == rhs.val();
    }
    friend bool operator!=(Z lhs, Z rhs) {
        return lhs.val() != rhs.val();
    }
    friend bool operator<(Z lhs, Z rhs) {
        return lhs.val() < rhs.val();
    }
};
```

## 快速幂

```cpp
ll qpow(ll x, ll y, const ll &mod = MOD) {
    ll ret = mod != 1;
    for (x %= mod; y; y >>= 1, x = x * x % mod)
        if (y & 1) ret = ret * x % mod;
    return ret; 
}
```

## 组合数

* 预处理

```cpp
ll C[M][M];
for (int i = 0; i < M; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j++) 
        C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
}
```
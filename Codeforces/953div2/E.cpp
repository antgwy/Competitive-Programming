#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
#define debug(x) cerr << #x << " is " << x << endl
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

void solve() {
    int n, q;
    string s, t;
    cin >> n >> s >> t;
    cin >> q;

    auto check = [&](int i, int l, int r) {
        if (s[i] == '1') return true;
        if ((i - 1 < l || t[i-1] == '0') && (i - 2 < l || s[i-2] == '1'))
            return false;
        if (i + 1 <= r && t[i+1] == '1') return true;
        return i + 2 <= r && s[i+2] == '0';
    };
    
    vector<int> sum(n + 1, 0);
    for (int i = 0; i < n; i++) {
        sum[i+1] = sum[i] + check(i, 0, n - 1);
    }

    while (q--) {
        int l, r, ans = 0;
        cin >> l >> r;
        if (r - l <= 4) {
            for (int i = l - 1; i < r; i++) ans += check(i, l - 1, r - 1);
        }
        else {
            ans = sum[r-2] - sum[l+1];
            for (int i : {l - 1, l, r - 2, r - 1}) ans += check(i, l - 1, r - 1);
        }
        cout << ans << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
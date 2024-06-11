#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
#define debug(x) cerr << #x << " is " << x << endl
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    if (count(s.begin(), s.end(), 'a') == n) {
        cout << n - 1 << "\n";
        return;
    }
    vector<int> p;
    for (int i = 0; i < n; i++) {
        if (s[i] != 'a') p.push_back(i);
    }
    int m = p.size();
    ll ans = 0;
    for (int c = 1; c <= m; c++) {
        if (m % c) continue;
        int ok = 1;
        for (int i = c; i < m; i++) {
            if (s[p[i]] != s[p[i-c]]) {
                ok = 0;
                break;
            }
            if (i % c != 0 && p[i] - p[i-c] != p[i-1] - p[i-c-1]) {
                ok = 0;
                break;
            }
        }
        if (!ok) continue;
        int l = p[0], r = n - 1 - p[m-1];
        int s = n;
        for (int i = c; i < m; i += c) {
            s = min(s, p[i] - p[i-1] - 1);
        }
        for (int x = 0; x <= l; x++) {
            // debug(max(0, min(r, s - x) + 1));
            ans += max(0, min(r, s - x) + 1);
        }
    }
    cout << ans << "\n";
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
/*
1
abbabba

b
bb
abb
bba
bbabb
abbabb
bbabba
abbabba
8
*/
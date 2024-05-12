#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cerr << #x << " is " << x << endl
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 5;

int fa[N];

int find(int x) {
    if (fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

void unite(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx == fy) return;
    fa[fx] = fy;
}

void solve() {
    int n;
    cin >> n;

    memset(fa, 0, sizeof(fa));
    for (int i = 1; i <= n; i++) fa[i] = i;

    vector<int> a(n + 1);
    unordered_map<int, int> mp, m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mp[a[i]] = i;
    } 

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 4; j++) {
            if (mp.count(a[i] ^ j)) {
                unite(i, mp[a[i]^j]);
            }
        }
    }

    int tot = 0;
    vector<vector<int> > v(n + 1);
    for (int i = 1; i <= n; i++) {
        int rt = find(i);
        if (!m.count(rt)) m[rt] = ++tot;
        v[m[rt]].push_back(i);
    }

    for (int i = 1; i <= tot; i++) {
        int sz = v[i].size();
        vector<int> b(sz);
        for (int j = 0; j < sz; j++) {
            b[j] = a[v[i][j]];
        }
        sort(b.begin(), b.end());
        for (int j = 0; j < sz; j++) {
            a[v[i][j]] = b[j];
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << a[i] << " \n"[i == n];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
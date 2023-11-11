#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << " is " << x << endl
typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 5;

int n, q;
ll fa[N], w[N];

int find(int x) {
    if (fa[x] == x) return x;
    int rt = find(fa[x]);
    w[x] = w[fa[x]] + w[x];
    return fa[x] = rt;
}

bool unite(int x, int y, ll z) {
    int fx = find(x), fy = find(y);
    if (fx == fy) return w[y] - w[x] == z;
    fa[fx] = fy;
    w[fx] = w[y] - w[x] - z;
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) fa[i] = i;
    ll a, b, d;
    for (int i = 1; i <= q; ++i) {
        cin >> a >> b >> d;
        if (unite(a, b, d)) cout << i << " ";
    }
    cout << "\n";
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cerr << #x << " is " << x << endl
typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 5;

int n, m;
int a[N], b[N], d[N], fa[N];

int find(int x) {
	if (fa[x] == x) return x;
	int root = find(fa[x]);
	d[x] += d[fa[x]];
	return fa[x] = root;
}

bool unite(int x, int y) {
	int fx = find(x);
	int fy = find(y);
	if (fx == fy) {
		if ((d[x] - d[y]) & 1) return 1;
		return 0;
	}
	fa[fx] = fy;
	d[fx] = d[y] - d[x] + 1 ;
	return 1;
}

int main()
{
	ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) cin >> a[i];
    for (int i = 1; i <= m; ++i) cin >> b[i];
    for (int i = 1; i <= n; ++i) fa[i] = i;
	int f = 1;
	for (int i = 1; i <= m; ++i) {
		if (!unite(a[i], b[i])) { f = 0; break; }
	}
    if (f) cout << "Yes\n";
    else cout << "No\n";
	return 0;
}
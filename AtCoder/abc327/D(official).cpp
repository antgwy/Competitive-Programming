#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cerr << #x << " is " << x << endl
typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 5;

int n, m;
int a[N], b[N];

int main()
{
	ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) cin >> a[i];
    for (int i = 1; i <= m; ++i) cin >> b[i];
    vector<vector<int> > g(n + 1, vector<int>());
	for (int i = 1; i <= m; ++i) {
		g[a[i]].push_back(b[i]);
		g[b[i]].push_back(a[i]);
	}
	vector<int> x(n + 1);
	for (int i = 1; i <= n; ++i) x[i] = -1;
	bool yes = true;
	function<void(int, int)> dfs = [&](int c, int v) -> void {
		x[c] = v;
		for (auto &d : g[c]) {
			if (x[d] == -1) dfs(d, v ^ 1);
			else if (x[d] == x[c]) yes = false;
		}
	};
	for (int i = 1; i <= n; ++i) {
		if (x[i] == -1) dfs(i, 0);
	}
	cout << (yes ? "Yes" : "No") << "\n";
	return 0;
}
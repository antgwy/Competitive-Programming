#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << " is " << x << endl
typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const int N = 1005;

int n, w[N], x[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> w[i] >> x[i];
    int res = 0;
    for (int t = 0; t < 24; ++t) {
        int cnt = 0;
        for (int i = 0; i <= n; ++i) {
            int st = (x[i] - t + 24) % 24;
            if (st >= 9 && st + 1 <= 18) cnt += w[i];
        }
        res = max(res, cnt);
    }
    cout << res << "\n";
    return 0;
}

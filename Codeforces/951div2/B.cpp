#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
#define debug(x) cerr << #x << " is " << x << endl
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

int lowbit(int x) { return x & -x; }

void solve() {
    int x, y;
    cin >> x >> y;
    int cnt = 0;
    for (int i = 0; i < 31; i++) {
        cnt++;
        if ((x >> i & 1) == (y >> i & 1)) continue;
        cout << (1 << i) << "\n";
        break;
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
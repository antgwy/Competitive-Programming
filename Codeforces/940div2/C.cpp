#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cerr << #x << " is " << x << endl
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;
const int N = 3e5 + 1;
const ll MOD = 1e9 + 7;
ll a[N];

void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= k; ++i) {
        int x, y;
        cin >> x >> y;
        if (x == y) n--;
        else n -= 2;
    }   
    cout << a[n] << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    a[0] = 1, a[1] = 1;
    for (int i = 2; i < N; ++i) {
        a[i] = (1ll * a[i-1] + 2ll * (i - 1) * a[i-2]) % MOD;
    }
    while (tt--) {
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
#define debug(x) cerr << #x << " is " << x << endl
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

void solve() {
    int n, m, p, q;
    cin >> n >> m >> p >> q;
    if (!(n % p) && m % q) cout << "NO\n";
    else if (!(n % p) && !(m % q) && n * q != m * p) cout << "NO\n";
    else cout << "YES\n";
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
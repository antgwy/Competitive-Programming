#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cerr << #x << " is " << x << endl
typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;

void solve() {
    ll n, k;
    cin >> n >> k;
    if (n < k) cout << "NO\n";
    else if (n == k) cout << "YES\n1\n1\n";
    else if (n + 1 < 2 * k) cout << "NO\n";
    else cout << "YES\n2\n" << n - k + 1 << " 1\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
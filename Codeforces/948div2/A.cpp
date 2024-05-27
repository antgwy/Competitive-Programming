#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
#define debug(x) cerr << #x << " is " << x << endl
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

void solve() {
    int n, m;
    cin >> n >> m;
    if (n >= m && (n - m) % 2 == 0) cout << "Yes\n";
    else cout << "No\n";
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
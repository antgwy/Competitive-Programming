#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cerr << #x << " is " << x << endl
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    if ((a + b + c) & 1) {
        cout << "-1\n"; return;
    }
    cout << min(a + b, (a + b + c) / 2) << "\n";
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
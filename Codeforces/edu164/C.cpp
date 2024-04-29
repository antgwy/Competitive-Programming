#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cerr << #x << " is " << x << endl
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

void solve() {
    string x, y;
    cin >> x >> y;
    int n = x.size(), p = 0, f = 0;
    while (x[p] == y[p]) p++;
    if (x[p] > y[p]) f = 1;
    p++;
    for (; p < n; p++) {
        if (f && x[p] > y[p]) swap(x[p], y[p]);
        else if (!f && x[p] < y[p]) swap(x[p], y[p]);
    }
    cout << x << "\n" << y << "\n";
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
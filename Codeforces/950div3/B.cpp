#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
#define debug(x) cerr << #x << " is " << x << endl
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

void solve() {
    int n, f, k;
    cin >> n >> f >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int gt = 0, eq = 0;
    for (int i = 0; i < n; i++) {
        gt += (a[i] > a[f-1]);
        eq += (a[i] == a[f-1]);
    }
    if (k <= gt) cout << "NO\n";
    else if (k < gt + eq) cout << "MAYBE\n";
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
#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cerr << #x << " is " << x << endl
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    n = a.size();
    int cur = 1;
    for (int i = n - 1; i > 0; --i) {
        a[i] -= a[i-1];
    }
    for (int i = n - 2; i >= 0; --i) {
        if (a[i] == 1) cur ^= 1;
        else cur = 1;
    }
    cout << (cur ? "Alice" : "Bob") << "\n";
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
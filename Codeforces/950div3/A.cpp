#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
#define debug(x) cerr << #x << " is " << x << endl
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

void solve() {
    int n, m;
    string s;
    cin >> n >> m;
    cin >> s;
    vector<int> c(7, 0);
    for (auto ch : s) {
        c[ch-'A']++;
    }
    int ans = 0;
    for (int i = 0; i < 7; i++) {
        ans += max(0, m - c[i]);
    }
    cout << ans << "\n";
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
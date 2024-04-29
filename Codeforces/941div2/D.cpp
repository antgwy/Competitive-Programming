#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << " is " << x << endl
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

void solve() {
    int n, k;
    cin >> n >> k;
    int s = k - 1;
    vector<int> ans;
    for (int i = 1; i <= s; i <<= 1) {
        ans.push_back(i);
        s -= i;
    }
    if (s) ans.push_back(s);
    for (int i = k + 1; i <= n; i <<= 1) {
        ans.push_back(i);
    }
    ans.push_back(2 * k + 1);
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " \n"[i == ans.size() - 1];
    }
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
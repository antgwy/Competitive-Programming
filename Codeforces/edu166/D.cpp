#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
#define debug(x) cerr << #x << " is " << x << endl
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> pre(n + 1, 0);
    for (int i = 0; i < n; i++) {
        pre[i+1] = pre[i] + (s[i] == '(' ? 1 : -1);
    }
    ll ans = 0;
    /*
    vector<vector<int> > vec(n + 1);
    for (int i = 0; i <= n; i++) {
        vec[pre[i]].push_back(i);
    }
    set<int> hi;
    for (int i = n / 2, j = n; i >= 0; i--) {
        while (j > 2 * i) {
            for (auto x : vec[j]) {
                hi.insert(x);
            }
            j--;
        }
        int cnt = 1;
        for (int k = 1; k < vec[i].size(); k++) {
            auto it = hi.lower_bound(vec[i][k-1]);
            if (it != hi.end() && *it < vec[i][k]) {
                cnt = 0;
            }
            ans += cnt;
            cnt++;
        }
    }
    cout << ans << "\n";
    */

    vector<int> cnt(*max_element(pre.begin(), pre.end()) + 1);
    for (auto x : pre) {
        cnt[x]++;
        int &c = cnt[(x-1)/2];
        ans += 1ll * c * (c - 1) / 2;
        c = 0;
    }
    for (auto c : cnt) ans += 1ll * c * (c - 1) / 2;
    cout << ans << "\n";
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
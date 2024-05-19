#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << " is " << x << endl
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> c[i];
    }
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](int i, int j) {
        return a[i] < a[j];
    });
    set<int> ans;
    int mi = INF;
    for (int i = n - 1; i >= 0; i--) {
        if (c[p[i]] < mi) {
            mi = c[p[i]];
            ans.insert(p[i] + 1);
        }
    }
    cout << ans.size() << "\n";
    for (auto e : ans) cout << e << " ";
    cout << "\n";
    return 0;
}
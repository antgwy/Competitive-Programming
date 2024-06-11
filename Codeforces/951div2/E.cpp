#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
#define debug(x) cerr << #x << " is " << x << endl
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

void solve() {
    int n, d;
    cin >> n >> d;
    vector<tuple<int, int, int> > p(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        tie(x, y) = make_pair(x - y, x + y);
        p[i] = make_tuple(x, y, i + 1);
    }
    auto ans = make_tuple(0, 0, 0);

    for (int i = 0; i < 2; i++) {
        map<int, map<int, int> > mm;
        for (auto& [x, y, id] : p) {
            swap(x, y);
            mm[x][y] = id;
        }

        for (auto& [x, m] : mm) {
            for (auto [y, i] : m) {
                if (m.count(y + d)) {
                    int j = m[y+d];
                    for (int e : {-d, d}) {
                        if (mm.count(x + e)) {
                            auto it = mm[x+e].lower_bound(y);
                            if (it != mm[x+e].end() && it->first <= y + d) {
                                ans = {i, j, it->second};
                            }
                        }
                    }
                }
            }
        }
    }

    auto [i, j, k] = ans;
    cout << i << " " << j << " " << k << "\n";
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
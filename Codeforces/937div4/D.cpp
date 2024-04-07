#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cerr << #x << " is " << x << endl
typedef long long ll;
typedef pair<int, int> P;
const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    vector<int> p, v(N, 0);
    v[1] = 1;
    for (int i = 2; i < 32; ++i) {
        int x = 0;
        for (int j = 4; j >= 0; --j) {
            x = 10 * x + ((i >> j) & 1);
        }
        p.push_back(x);
        v[x] = 1;
    }
    auto check = [&](auto self, int x) -> int {
        if (v[x]) return v[x];
        int y = x;
        for (int i = 0; i < (int)p.size(); ++i) {
            if (p[i] > y) break;
            if (y % p[i]) continue;
            y = y / p[i];
            if (v[y]) return v[x] = v[y];
            else return v[x] = self(self, y);
        }
        return v[x] = -1;
    };
    while (t--) {
        int n;
        cin >> n;
        if (check(check, n) == 1) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
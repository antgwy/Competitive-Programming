#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define debug(x) cerr << #x << " is " << x << endl
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> s(m), r(m);
    for (int i = 0; i < m; i++) {
        int c;
        cin >> c;
        for (int j = 0; j < c; j++) {
            int x;
            cin >> x;
            x--;
            s[i] |= 1 << x;
        }
        char ch;
        cin >> ch;
        r[i] = (ch == 'o');
    }

    int ans = 0;
    for (int mask = 0; mask < 1 << n; mask++) {
        int ok = 1;
        for (int i = 0; i < m; i++) {
            ok &= ((__builtin_popcount(s[i] & mask) >= k) == r[i]);
        }
        ans += ok;
    }
    cout << ans << "\n";
    return 0;
}
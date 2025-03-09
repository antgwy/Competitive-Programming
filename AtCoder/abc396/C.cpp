#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define debug(x) cerr << #x << " is " << x << endl
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> b(n), w(m);
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < m; i++) cin >> w[i];
    sort(b.begin(), b.end(), greater<int>());
    sort(w.begin(), w.end(), greater<int>());
    int p = 0, q = 0;
    ll ans = 0;
    while (p < n && q < m) {
        if (b[p] >= 0) {
            ans += b[p];
            if (w[q] >= 0) ans += w[q];
        } 
        else if (b[p] < 0 && b[p] + w[q] >= 0) {
            ans += (b[p] + w[q]);
        }
        else break;
        p++; q++;
    }
    for (; q < min(p, m); q++) {
        if (w[q] > 0) ans += w[q];
    }
    for (; p < n; p++) {
        if (b[p] > 0) ans += b[p];
    }
    cout << ans << "\n";
    return 0;
}
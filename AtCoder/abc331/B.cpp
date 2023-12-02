#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cerr << #x << " is " << x << endl
typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, s, m, l;
    cin >> n >> s >> m >> l;
    int ans = INF;
    for (int i = 0; (i - 1) * 6 <= n; ++i) {
        for (int j = 0; i * 6 + (j - 1) * 8 <= n; ++j) {
            for (int k = 0; i * 6 + j * 8 + (k - 1) * 12 <= n; ++k) {
                if (12 * k + 8 * j + 6 * i >= n) {
                    ans = min(ans, i * s + j * m + k * l);
                }
            } 
        }
    }
    cout << ans << "\n";
    return 0;
}
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
    int m;
    cin >> m;
    int x, w;
    array<int, 30> cnt{};
    while (m--) {
        cin >> x >> w;
        if (x == 1) {
            cnt[w]++;
        }
        else if (x == 2) {
            for (int i = 29; i >= 0; --i) {
                int x = min(w >> i, cnt[i]);
                w -= x << i;
            }
            if (!w) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}
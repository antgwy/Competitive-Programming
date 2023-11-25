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
    ll d, ans = 1e18;
    cin >> d;
    int up = (int)sqrt(d) + 1;
    for (int x = 0; x <= up; ++x) {
        int y = (int)sqrt(d - 1ll * x * x);
        ans = min(ans, abs(1ll * x * x + 1ll * y * y - d));
        y++;
        ans = min(ans, abs(1ll * x * x + 1ll * y * y - d));
    }
    cout << ans << "\n";
    return 0;
}
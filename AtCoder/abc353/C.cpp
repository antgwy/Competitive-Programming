#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cerr << #x << " is " << x << endl
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;
const int MOD = 1e8;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ans += a[i];
    }
    ans = ans * (n - 1);
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        int id = lower_bound(a.begin(), a.end(), MOD - a[i]) - a.begin();
        id = max(id, i + 1);
        ans -= 1ll * (n - id) * MOD;
    }
    cout << ans << "\n";
    return 0;
}
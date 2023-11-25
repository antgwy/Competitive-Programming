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
    int n, l;
    cin >> n >> l;
    int ans = 0, x;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        ans += (x >= l);
    }
    cout << ans << "\n";
    return 0;
}
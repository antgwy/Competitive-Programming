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
    int n, m;
    cin >> n >> m;
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        if (x <= m) res += x;
    }
    cout << res << "\n";
    return 0;
}
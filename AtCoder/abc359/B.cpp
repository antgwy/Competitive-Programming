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
    int n;
    cin >> n;
    vector<int> p(n + 1, -1);
    int ans = 0;
    for (int i = 0; i < 2 * n; i++) {
        int x;
        cin >> x;
        if (p[x] == -1) p[x] = i;
        else if (i - p[x] == 2) ans++;
    }
    cout << ans << "\n";
    return 0;
}
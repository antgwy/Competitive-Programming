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
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int ma = *max_element(a.begin() + 1, a.end());
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] == ma) continue;
        res = max(res, a[i]);
    }
    cout << res << "\n";
    return 0;
}
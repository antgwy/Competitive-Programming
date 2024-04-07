#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cerr << #x << " is " << x << endl
typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    string str;
    cin >> str;
    int res = 0;
    for (auto &c : str) res += (c == '1');
    if (res == 2) {
        int f = 0;
        for (int i = 1; i < n; ++i) {
            if (str[i] == '1' && str[i-1] == '1') {
                f = 1; break;
            }
        }
        cout << (f ? "NO" : "YES") << "\n";
        return;
    }
    res %= 2;
    cout << (res ? "NO" : "YES") << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
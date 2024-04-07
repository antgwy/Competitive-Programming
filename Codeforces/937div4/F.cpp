#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cerr << #x << " is " << x << endl
typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a + 1 != c) { cout << "-1\n"; return; }
    queue<int> q;
    q.push(0);
    int res;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        res = x;
        if (a) {
            a--;
            q.push(x + 1);
            q.push(x + 1);
        }
        else if (b) {
            b--;
            q.push(x + 1);
        }
    }
    cout << res << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
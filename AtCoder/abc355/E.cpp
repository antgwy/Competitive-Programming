#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define debug(x) cerr << #x << " is " << x << endl
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, l, r;
    cin >> n >> l >> r;
    const int bin = 1 << n;
    vector<int> nxt(bin + 1, -1);
    queue<int> q;
    q.push(l);
    nxt[l] = l;
    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (int i = 1; i <= bin; i *= 2) {
            for (auto y : {x - i, x + i}) {
                if (y < 0 || y > bin) continue;
                if (nxt[y] == -1) {
                    nxt[y] = x;
                    q.push(y);
                }
            }
            if (x & i) break;
        }
    }

    int ans = 0;
    for (int i = r + 1; i != l; i = nxt[i]) {
        int a = nxt[i], b = i;
        int f = 1;
        if (a > b) {
            swap(a, b);
            f = -1;
        }
        cout << "? " << __lg(b - a) << " " << a / (b - a) << endl;
        int res;
        cin >> res;
        ans = (ans + f * res + 100) % 100;
    }
    cout << "! " << ans << endl;
    return 0;
}
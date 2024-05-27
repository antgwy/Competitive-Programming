#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
#define debug(x) cerr << #x << " is " << x << endl
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    map<char, pii> d;
    d['N'] = {0, 1}; d['S'] = {0, -1};
    d['E'] = {1, 0}; d['W'] = {-1, 0};
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        auto [dx, dy] = d[s[i]];
        x += dx;
        y += dy;
    }
    if ((x & 1) || (y & 1)) { cout << "NO\n"; return; }
    if (!x && !y && n == 2) { cout << "NO\n"; return; }
    x /= 2; y /= 2;
    auto [dx, dy] = d[s[0]];
    x -= dx; y -= dy;
    cout << "R";
    for (int i = 1; i < n; i++) {
        if (s[i] == 'E' && x > 0) {
            cout << "R";
            x--;
        }
        else if (s[i] == 'W' && x < 0) {
            cout << "R";
            x++;
        }
        else if (s[i] == 'N' && y > 0) {
            cout << "R";
            y--;
        }
        else if (s[i] == 'S' && y < 0) {
            cout << "R";
            y++;
        }
        else cout << "H";
    }
    cout << "\n";
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
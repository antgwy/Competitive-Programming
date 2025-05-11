#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
#define debug(x) cerr << #x << " is " << x << endl
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<vector<int> > a(n, vector<int>(n, -1));
    int x = 0, y = 0, id = 0, cur = n * n - 1;
    for (int k = 0; k < n * n; k++) {
        a[x][y] = cur--;
        int nx = x + dir[id][0];
        int ny = y + dir[id][1];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n || a[nx][ny] != -1) {
            id = (id + 1) % 4;
        }
        x += dir[id][0];
        y += dir[id][1];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " \n"[j == n - 1];
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
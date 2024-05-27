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
    int n, m;
    cin >> n >> m;
    vector<int> c(201, 0);
    int x;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        c[x] = 1;
    }
    for (int i = 1; i <= m; i++) {
        cin >> x;
        c[x] = 2;
    }
    int lst = 0;
    for (int i = 1; i <= 200; i++) {
        if (!c[i]) continue;
        if (c[i] == 1 && c[i] == lst) { cout << "Yes\n"; exit(0); }
        lst = c[i];
    }
    cout << "No\n";
    return 0;
}
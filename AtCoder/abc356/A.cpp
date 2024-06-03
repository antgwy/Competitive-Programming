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
    for (int i = 1; i <= n; i++) {
        cout << (i >= l && i <= r ? r - i + l : i) << " \n"[i == n];
    }
    return 0;
}
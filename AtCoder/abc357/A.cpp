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
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;
        if (m >= 0) {
            m -= h;
            if (m < 0) cout << i << "\n";
        }
    }
    if (m >= 0) cout << n << "\n";
    return 0;
}
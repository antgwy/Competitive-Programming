#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cerr << #x << " is " << x << endl
typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int id = n + 1;
    for (int i = 1; i <= n; ++i) {
        if (a[i] > a[k]) {
            id = i; break;
        }
    }
    if (id < k) {
        int mid = k;
        for (int i = id + 1; i <= k; ++i) {
            if (a[i] > a[k]) {
                mid = i; break;
            }
        }
        if (id != 1) cout << max(id - 2, mid - id) << "\n";
        else cout << mid - 2 << "\n";
    }
    else {
        cout << id - 2 << "\n";
    }
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
#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cerr << #x << " is " << x << endl
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

void solve() {
    int k, q;
    cin >> k >> q;
    vector<int> a(k);
    for (int i = 0; i < k; ++i) cin >> a[i];
    for (int i = 0; i < q; ++i) {
        int x;
        cin >> x;
        cout << (x < a[0] ? x : a[0] - 1) << " \n"[i == q - 1]; 
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
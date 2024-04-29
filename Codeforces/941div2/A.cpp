#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cerr << #x << " is " << x << endl
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> cnt(101);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    for (int i = 1; i <= 100; ++i) {
        if (cnt[i] >= k) {
            cout << k - 1 << "\n";
            return;
        }
    }
    cout << n << "\n";

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
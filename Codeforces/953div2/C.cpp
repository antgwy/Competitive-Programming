#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
#define debug(x) cerr << #x << " is " << x << endl
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

void solve() {
    int n;
    ll k;
    cin >> n >> k;
    ll mx;
    if (n & 1) mx = 1ll * (n + 1) * (n - 1) / 2;
    else mx = 1ll * n * n / 2;
    if (k & 1 || k > mx) { cout << "No\n"; return; }
    vector<int> a(n + 1);
    iota(a.begin(), a.end(), 0);
    int l = 1, r = n;
    while (k > 0 && l < r) {
        if (k > 2 * (r - l)) {
            k -= 2 * (r - l);
            swap(a[l], a[r]);
            l++;
            r--;
        }
        else {
            r = l + k / 2;
            k -= 2 * (r - l);
            swap(a[l], a[r]);
        }
    } 
    // if (k > 0) { cout << "No\n"; return; }
    cout << "Yes\n";
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " \n"[i == n];
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
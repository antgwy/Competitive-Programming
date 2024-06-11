#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
#define debug(x) cerr << #x << " is " << x << endl
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n - 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        b[i] = __gcd(a[i], a[i+1]);
    }
    
    int bad = 0;
    for (int i = 1; i < n - 1; i++) {
        bad += b[i-1] > b[i];
    }
    bool f = false;
    if (bad - (b[0] > b[1]) == 0 || bad - (b[n-3] > b[n-2]) == 0) {
        f = true;
    }
    for (int i = 1; i < n - 1; i++) {
        int tmp = bad;
        tmp -= b[i-1] > b[i];
        int g = __gcd(a[i-1], a[i+1]);
        if (i - 1 > 0) {
            tmp -= b[i-2] > b[i-1];
            tmp += b[i-2] > g;
        }
        if (i + 1 < n - 1) {
            tmp -= b[i] > b[i+1];
            tmp += g > b[i+1];
        }
        if (tmp == 0) f = true;
    }
    cout << (f ? "YES" : "NO") << "\n";
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
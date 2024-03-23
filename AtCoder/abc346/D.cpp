#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cerr << #x << " is " << x << endl
typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const ll inf = 2e18 + 5;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string str;
    cin >> n;
    cin >> str;
    vector<int> c(n);
    for (auto &e : c) cin >> e;
    vector<ll> pre0(n, 0), pos0(n, 0);
    vector<ll> pre1(n, 0), pos1(n, 0);
    ll c0 = 0, c1 = 0;
    for (int i = 0; i < n; ++i) {
        if (i & 1) {
            if (str[i] == '1') c1 += c[i];
            else c0 += c[i];
        }
        else {
            if (str[i] == '0') c1 += c[i];
            else c0 += c[i];
        }
        pre0[i] = c0; 
        pre1[i] = c1;
    }
    c0 = 0, c1 = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (i & 1) {
            if (str[i] == '0') c1 += c[i];
            else c0 += c[i];
        }
        else {
            if (str[i] == '1') c1 += c[i];
            else c0 += c[i];
        }
        pos0[i] = c0;
        pos1[i] = c1;
    }
    ll ans = inf;
    for (int i = 0; i < n - 1; ++i) {
        ans = min(ans, pre0[i] + pos0[i + 1]);
        ans = min(ans, pre1[i] + pos1[i + 1]);
    }
    cout << ans << "\n";
    return 0;
}
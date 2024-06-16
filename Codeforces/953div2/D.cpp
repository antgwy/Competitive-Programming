#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
#define debug(x) cerr << #x << " is " << x << endl
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

void solve() {
    int n, c;
    cin >> n >> c;
    vector<ll> a(n);
    vector<ll> sum(n + 1, 0);
    int mx = -1, id;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum[i+1] = sum[i] + a[i];
        if (a[i] > mx) {
            mx = a[i];
            id = i;
        }
    }

    /*vector<int> idx(n), rk(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&a](int i, int j){
        return a[i] > a[j];
    });
    for (int i = 0; i < n; i++) {
        rk[idx[i]] = i;
    }
    vector<ll> s(n + 1, 0);
    for (int i = 0; i < n; i++) {
        s[i+1] = s[i] + a[idx[i]];
    }*/
    
    vector<int> ex(n, -1);
    if (a[0] + c >= a[id]) ex[0] = 0;
    else ex[id] = 0;

    for (int i = 0; i < n; i++) {
        if (ex[i] != -1) continue;
        if (sum[i] + a[i] + c >= a[id]) ex[i] = i;
        else ex[i] = i + 1;
    }

    for (int i = 0; i < n; i++) {
        cout << ex[i] << " \n"[i == n - 1];
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
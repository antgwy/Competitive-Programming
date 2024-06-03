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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    const int M = *max_element(a.begin(), a.end());
    vector<int> c(M + 1);
    for (auto x : a) c[x]++;
    for (int i = 1; i <= M; i++) c[i] += c[i-1];

    ll ans = 0;
    for (int x = 1; x <= M; x++) {
        int d = c[x] - c[x-1];
        ans += (ll)d * (d - 1) / 2;
        for (int k = 1; k * x <= M; k++) {
            ans += (ll)k * (c[min(M, (k+1)*x-1)] - c[max(k*x-1, x)]) * d;
        }
    } 
    cout << ans << "\n";
    return 0;
}
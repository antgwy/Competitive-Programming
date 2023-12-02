#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cerr << #x << " is " << x << endl
typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> b(a);
    sort(b.begin(), b.end());
    vector<ll> sum(n + 1);
    for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i-1] + 1ll * b[i-1];
    }
    for (int i = 0; i < n; ++i) {
        auto it = upper_bound(b.begin(), b.end(), a[i]);
        if (it == b.end()) cout << "0 ";
        else {
            int id = it - b.begin();
            cout << sum[n] - sum[id] << " ";
        }  
    }
    cout << "\n";
}
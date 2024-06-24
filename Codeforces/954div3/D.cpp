#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
#define debug(x) cerr << #x << " is " << x << endl
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    if (n == 2) { cout << stoi(s) << "\n"; return; }
    if (s[0] == '0' || s[n-1] == '0') { cout << "0\n"; return; }
    vector<int> a(n), z;
    for (int i = 0; i < n; i++) a[i] = s[i] - '0';
    if (n == 3) {
        int x = a[0] * 10 + a[1];
        int y = a[1] * 10 + a[2];
        cout << min({x * a[2], x + a[2], a[0] * y, a[0] + y}) << "\n";
        return;
    }
    
    for (int i = 0; i < n; i++) {
        if (!a[i]) z.push_back(i);
    }

    if (z.size() >= 1) { cout << "0\n"; return; }

    int ans = INF;
    for (int i = 0; i + 1 < n; i++) {
        int x = a[i] * 10 + a[i+1];
        auto b = a;
        b[i+1] = x;
        b.erase(b.begin() + i);
        int sum = 0;
        for (int j = 0; j < n - 1; j++) { 
            if (b[j] != 1) {
                sum += b[j];
            }
        }
        ans = min(ans, sum);
    }
    cout << ans << "\n";
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
#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
#define debug(x) cerr << #x << " is " << x << endl
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

void solve() {
    string x;
    cin >> x;
    bool f = true;
    if (x.front() != '1' || x.back() == '9') f = false;
    for (int i = 1; i < (int)x.size() - 1; i++) {
        f &= (x[i] != '0');
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
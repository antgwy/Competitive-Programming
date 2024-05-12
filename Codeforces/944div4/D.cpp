#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cerr << #x << " is " << x << endl
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

void solve() {
    string s;
    cin >> s;
    int n = s.size(), cnt = 1, f = 0;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == '1' && s[i+1] == '0') cnt++;
        else if (s[i] == '0' && s[i+1] == '1') {
            cnt += f;
            f = 1;
        } 
    }
    cout << cnt << "\n";
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
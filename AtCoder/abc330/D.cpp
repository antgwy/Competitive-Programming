#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cerr << #x << " is " << x << endl
typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f, N = 2005;

string s[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> row(n + 1), col(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        for (int j = 0; j < n; ++j) {
            if (s[i][j] == 'o') {
                row[i]++;
                col[j]++;
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (s[i][j] == 'o') {
                ans += 1ll * (row[i] - 1) * (col[j] - 1);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
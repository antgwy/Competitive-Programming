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
    int n, q;
    string s;
    cin >> n >> q >> s;
    vector<int> sum(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        sum[i + 1] = sum[i] + (s[i] == s[i+1]);
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << sum[r-1] - sum[l-1] << "\n";
    }
    return 0;
}
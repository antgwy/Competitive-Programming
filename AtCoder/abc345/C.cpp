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
    string str;
    cin >> str;
    vector<int> cnt(26);
    int n = str.length();
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        int c = str[i] - 'a';
        ans += 1ll * (i - cnt[c]);
        cnt[c]++;
    }
    for (int i = 0; i < 26; ++i) {
        if (cnt[i] > 1) {
            ans++; break;
        }
    }
    cout << ans << "\n";
    return 0;
}
// Time limit exceeded on test 4
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
    int t;
    cin >> t;
    int n;
    string s;

    auto calc = [&](string str) {
        int l = str.size();
        vector<int> pi(l, 0);
        for (int i = 1; i < l; ++i) {
            int j = pi[i-1];
            while (j > 0 && str[i] != str[j]) {
                j = pi[j-1];
            }
            if (str[i] == str[j]) ++j;
            pi[i] = j;
        }
        return pi;
    };
    while (t--) {
        cin >> n >> s;
        int ans = n;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 26; ++j) {
                int diff = j - s[i] + 'a';
                string ss = s.substr(0, i) + char(s[i] + diff) + s.substr(i + 1);
                auto pi = calc(ss);
                int len = n - pi[n-1];
                if (n % len == 0) ans = min(ans, len);
            } 
        }
        cout << ans << "\n";
    }
    return 0;
}
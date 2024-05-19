// f[i]: 子串 LCP 长度为 i，最多划分几个子串，询问 l 答案为 f[i] >= l 最大的 i
#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cerr << #x << " is " << x << endl
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

vector<int> zfunc(string s) {
    int n = s.size();
    vector<int> z(n + 1);
    z[0] = n;
    for (int i = 1, j = 1; i < n; i++) {
        z[i] = max(0, min(j + z[j] - i, z[i-j]));
        while (i + z[i] < n && s[z[i]] == s[i+z[i]]) {
            z[i]++;
        }
        if (i + z[i] > j + z[j]) j = i;
    }
    return z;
}

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    string s;
    cin >> s;
    auto z = zfunc(s);

    set<int> st;
    vector<vector<int> > g(n + 1);
    for (int i = 0; i < n; i++) {
        g[z[i]].push_back(i);
    }
    vector<int> f(n + 1);
    f[0] = n;
    for (int i = n; i; i--) {
        st.insert(g[i].begin(), g[i].end());
        int x = 0, res = 1;
        while (true) {
            auto it = st.lower_bound(x + i);
            if (it == st.end()) break;
            res++;
            x = *it;
        }
        f[i] = res;
    }  
    for (int i = l, len = n; i <= r; i++) {
        while (len > 0 && f[len] < i) len--;
        cout << len << " \n"[i == r];
    }
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
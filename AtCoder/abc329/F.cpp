#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cerr << #x << " is " << x << endl
typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 5;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> c(n), a(q), b(q);
    for (int i = 0; i < n; ++i) cin >> c[i];
    for (int i = 0; i < q; ++i) {
        cin >> a[i] >> b[i];
        --a[i]; --b[i];
    }
    vector<set<int> > ss(n);
    for (int i = 0; i < n; ++i) ss[i].insert(c[i]);
    for (int i = 0; i < q; ++i) {
        if (ss[b[i]].size() < ss[a[i]].size()) {
            ss[b[i]].swap(ss[a[i]]);
        }
        for (int c : ss[a[i]]) {
            ss[b[i]].insert(c);
        }
        ss[a[i]].clear();
        cout << ss[b[i]].size() << "\n";
    }
    return 0;
}
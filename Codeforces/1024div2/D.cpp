#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
#define debug(x) cerr << #x << " is " << x << endl
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

int mergesort(vector<int>& v) {
    int n = v.size();
    if (n < 2) return 0;
    vector<int> l(v.begin(), v.begin() + n / 2);
    vector<int> r(v.begin() + n / 2, v.end());
    int ret = mergesort(l) ^ mergesort(r);
    int p = 0, q = 0, id = 0;
    while (p < (int)l.size() && q < (int)r.size()) {
        if (l[p] <= r[q]) v[id++] = l[p++];
        else {
            v[id++] = r[q++];
            ret ^= (((int)l.size() - p) & 1);
        }
    }
    while (p < (int)l.size()) v[id++] = l[p++];
    while (q < (int)r.size()) v[id++] = r[q++];
    return ret;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a, b;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (i & 1) b.push_back(x);
        else a.push_back(x);
    }
    int ia = mergesort(a);
    int ib = mergesort(b);
    int la = a.size(), lb = b.size();
    if (ia != ib) {
        if (n & 1) swap(a[la-1], a[la-2]); 
        else swap(b[lb-1], b[lb-2]);
    }
    for (int i = 0; i < n; i++) {
        if (i & 1) cout << b[i/2] << " \n"[i == n - 1];
        else cout << a[i/2] << " \n"[i == n - 1];
    }
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
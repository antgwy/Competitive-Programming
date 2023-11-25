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
    cin >> n >> q;
    vector<int> a(n + 1), cc(n + 1, 0);
    set<int> mex;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] <= n) cc[a[i]]++;
    }
    for (int i = 0; i <= n; ++i) {
        if (!cc[i]) {
            mex.insert(i);
        }
    }
    while (q--) {
        int id, x;
        cin >> id >> x;
        if (a[id] <= n) {
            cc[a[id]]--;
            if (!cc[a[id]]) mex.insert(a[id]);
        }
        if (x <= n) {
            if (!cc[x]) mex.erase(x);
            cc[x]++;
        }
        a[id] = x;
        cout << *mex.begin() << "\n";
    }
    return 0;
}
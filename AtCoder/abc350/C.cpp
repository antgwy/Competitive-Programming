#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cerr << #x << " is " << x << endl
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i]--;
    }
    vector<pii> ans;
    for (int i = 0; i < n; ++i) {
        while (a[i] != i) {
            int j = a[i];
            ans.emplace_back(i, j);
            swap(a[i], a[j]);
        }
    }
    cout << ans.size() << "\n";
    for (auto &op : ans) {
        cout << op.first + 1 << " " << op.second + 1 << "\n"; 
    }
    return 0;
}
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
    int n, q;
    cin >> n >> q;
    vector<int> t(n, 1);
    for (int i = 1; i <= q; ++i) {
        int x;
        cin >> x;
        t[x-1] ^= 1;
    }
    cout << accumulate(t.begin(), t.end(), 0) << "\n";
    return 0;
}
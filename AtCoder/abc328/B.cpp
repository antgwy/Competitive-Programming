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
    int n;
    cin >> n;
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        int x; 
        cin >> x;
        if (i < 10) {
            res += (x >= i) + (x >= i * 10 + i);
        }
        else if (i / 10 == i % 10) {
            res += (x >= i / 10) + (x >= i);
        }
    }
    cout << res << "\n";
    return 0;
}
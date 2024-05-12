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
    int n, k;
    cin >> n >> k;
    int x, cur = 0, res = 1;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (cur + x > k) {
            cur = x;
            res++;
        }
        else cur += x;
    }
    cout << res << "\n";
    return 0;
}
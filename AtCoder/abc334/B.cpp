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
    ll a, m, l, r;
    cin >> a >> m >> l >> r;
    ll L = l + ((a - l) % m + m) % m;
    ll R = r - ((r - a) % m + m) % m;
    cout << (R - L) / m + 1 << "\n";
    return 0;
}
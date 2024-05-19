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
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll w = c - a, h = d - b;
    ll s[5][3] = {{0, 0, 0}, {0, 2, 3}, {0, 3, 6}, {0, 3, 7}, {0, 4, 8}};
    auto f = [&](ll x, ll y) {
        ll sub1 = (x / 4) * (y / 2) * s[4][2];
        ll sub2 = (y / 2) * s[x%4][2];
        ll sub3 = (x / 4) * s[4][y%2];
        ll sub4 = s[x%4][y%2];
        return sub1 + sub2 + sub3 + sub4;
    };
    a = (a % 4 + 4) % 4;
    b = (b % 2 + 2) % 2;
    c = a + w;
    d = b + h;
    cout << f(c, d) - f(c, b) - f(a, d) + f(a, b) << "\n";
    return 0;
}
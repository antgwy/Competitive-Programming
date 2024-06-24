#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define debug(x) cerr << #x << " is " << x << endl
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    if ((sx + sy) & 1) sx--;
    if ((tx + ty) & 1) tx--;
    if (abs(tx - sx) <= abs(ty - sy)) cout << abs(ty - sy) << "\n";
    else {
        if (tx < sx) sx -= abs(ty - sy);
        else sx += abs(ty - sy);
        cout << abs(ty - sy) + abs(tx - sx) / 2 << "\n";
    }
    return 0;
}
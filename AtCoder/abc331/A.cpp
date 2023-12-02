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
    int M, D, y, m, d;
    cin >> M >> D >> y >> m >> d;
    d++;
    if (d == D + 1) { d = 1; m++; }
    if (m == M + 1) { m = 1; y++; }
    cout << y << " " << m << " " << d << "\n";
    return 0;
}
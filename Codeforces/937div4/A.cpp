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
    int t;
    int a, b, c;
    cin >> t;
    while (t--) {
        cin >> a >> b >> c;
        string ans = "NONE";
        if (a < b && b < c) ans = "STAIR";
        else if (a < b && b > c) ans = "PEAK";
        cout << ans << "\n";
    }
    return 0;
}
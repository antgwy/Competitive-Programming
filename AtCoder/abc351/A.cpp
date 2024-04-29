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
    int x, res = 1;
    for (int i = 0; i < 9; ++i) {
        cin >> x;
        res += x;
    }    
    for (int i = 0; i < 8; ++i) {
        cin >> x;
        res -= x;
    }
    cout << res << "\n";
    return 0;
}
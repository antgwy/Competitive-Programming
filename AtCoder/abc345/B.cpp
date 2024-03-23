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
    ll x;
    cin >> x;
    if (x >= 0) cout << (x + 9) / 10 << "\n";
    else cout << x / 10 << "\n";
    return 0;
}
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
    int h;
    cin >> h;
    for (int i = 1; i < 31; i++) {
        if ((1<<i) - 1 > h) { cout << i << "\n"; break; }
    }
    return 0;
}
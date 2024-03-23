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
    int w, b;
    cin >> w >> b;
    string str = "wbwbwwbwbwbw";
    str = str + str + str;
    if (w >= 14 || b >= 10) {
        int k = min(w / 7, b / 5) - 1;
        w -= k * 7;
        b -= k * 5;
    }
    int cw = 0;
    for (int i = 0; i < w + b; ++i) cw += (str[i] == 'w');
    for (int i = w + b; i < 36; ++i) {
        if (cw == w) { cout << "Yes\n"; exit(0); }
        cw += (str[i] == 'w') - (str[i-w-b] == 'w');
    }
    if (cw == w) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}
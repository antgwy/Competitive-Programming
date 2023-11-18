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
    int n, c = 0;
    string s;
    cin >> n >> s; s += ' ';
    vector<int> alpha(27);
    c++;
    for (int i = 1; i <= n; ++i) {
        if (s[i] != s[i-1]) {
            int x = s[i-1] - 'a';
            alpha[x] = max(alpha[x], c);
            c = 1;
        }
        else c++;
    } 
    int res = 0;
    for (int x : alpha) res += x;
    cout << res << "\n";
    return 0;
}
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
    string S, T;
    cin >> S >> T;
    int n = S.length(), p = 0, flag = 0;
    for (int i = 0; i < n; ++i) {
        if (toupper(S[i]) == T[p]) p++;
        if (T[2] == 'X' && p == 2) { flag = 1; break; }
        else if (p == 3) { flag = 1; break; }
    }
    if (flag) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}
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
    int n;
    string s, t;
    cin >> n >> s;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '1') {
            t += string(i + 1, 'A') + string(i, 'B');
        }
    }
    cout << t.size() << "\n" << t << "\n";
    return 0;
}
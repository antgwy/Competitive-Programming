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
    cin >> t;
    string s;
    while (t--) {
        cin >> s;
        int n = s.length(), c0 = 0;
        for (auto c : s) c0 += c == '0';
        if (c0 * 2 == n) { cout << "0\n"; continue; }
        int c1 = n - c0, res = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') c0--;
            else c1--;
            if (c0 < 0 || c1 < 0) { res = i; break; }
        }
        cout << n - res << "\n";    
    }
    return 0;
}
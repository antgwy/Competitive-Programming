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
    while (t--) {
        int n; 
        string s; 
        cin >> n >> s;
        for (int len = 1; len <= n; len++) {
            if (n % len) continue;
            int sum = 0;
            for (int i = 0; i < len; i++) {
                vector<int> cnt(26, 0);
                int mx = 0;
                for (int j = i; j < n; j += len) {
                    int c = s[j] - 'a';
                    cnt[c] += 1;
                    mx = max(mx, cnt[c]);
                }
                sum += mx;
            }
            if (sum >= n - 1) { cout << len << "\n"; break; }
        }
    }
    return 0;
}
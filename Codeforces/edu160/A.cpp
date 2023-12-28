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
    string ab;
    while (t--) {
        cin >> ab;
        int n = ab.length(), found = 0;
        for (int i = 1; i <= n / 2; ++i) {
            string a = ab.substr(0, i);
            string b = ab.substr(i);
            if (b[0] != '0' && stoi(a) < stoi(b)) {
                cout << a << " " << b << "\n";
                found = 1;
                break;
            }
        }
        if (!found) cout << "-1\n";
    }
    return 0;
}
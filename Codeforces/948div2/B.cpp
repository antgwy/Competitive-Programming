#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
#define debug(x) cerr << #x << " is " << x << endl
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

void solve() {
    int x;
    cin >> x;
    vector<int> a;
    while (x) {
        if (x % 2 == 0) a.push_back(0);
        else if (x % 4 == 1) {
            a.push_back(1);
            x--;
        }
        else {
            a.push_back(-1);
            x++;
        }
        x /= 2;
    }
    cout << a.size() << "\n";
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " \n"[i == a.size() - 1];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
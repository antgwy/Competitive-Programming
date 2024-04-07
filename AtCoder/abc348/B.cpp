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
    int n;
    cin >> n;
    vector<int> x(n + 1), y(n + 1);
    auto squ = [&](int x) {
        return x * x;
    };
    for (int i = 1; i <= n; ++i) cin >> x[i] >> y[i];
    for (int i = 1; i <= n; ++i) {
        int id = i, mx = 0;
        for (int j = 1; j <= n; ++j) {
            if (j == i) continue;
            int res = squ(x[i] - x[j]) + squ(y[i] - y[j]);
            if (mx < res) {
                id = j;
                mx = res;
            }
        }
        cout << id << "\n";
    }
    return 0;
}
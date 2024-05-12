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
    vector<int> c(6), v{1, 5, 10, 50, 100, 500};
    for (int i = 0; i < 6; i++) {
        cin >> c[i];
    }

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    bool flag = true;
    for (int i = 0; i < n; i++) {
        for (int j = 5; j >= 0; j--) {
            if (a[i] >= v[j] && c[j]) {
                int k = min(a[i] / v[j], c[j]);
                c[j] -= k;
                a[i] -= k * v[j];
            }
        }
        if (a[i]) { flag = false; break; }
    }
    cout << (flag ? "Yes" : "No") << "\n";
    return 0;
}
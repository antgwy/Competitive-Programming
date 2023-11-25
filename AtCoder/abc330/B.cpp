// official: std::clamp(A_i,L,R)
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
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n + 1), x(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] > r) x[i] = r;
        else if (a[i] < l) x[i] = l;
        else x[i] = a[i];
    }
    for (int i = 1; i <= n; ++i)
        cout << x[i] << " \n"[i == n];
    return 0;
}
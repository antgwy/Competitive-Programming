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
    vector<int> a(n);
    for (auto &e : a) cin >> e;
    for (int i = 1; i < n; ++i) {
        cout << a[i] * a[i-1] << " \n"[i == n - 1];
    }
    return 0;
}
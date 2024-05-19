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
    int n, m;
    cin >> n >> m;
    vector<int> ban(n + 1);
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        ban[a]++;
    }
    if (ban[1] || ban[n]) { cout << "-1\n"; exit(0); }
    vector<int> p(n + 1);
    iota(p.begin(), p.end(), 0);
    for (int i = 1; i <= n; i++) {
        if (ban[i]) swap(p[i], p[i+1]);
    }
    for (int i = 1; i <= n; i++)
        cout << p[i] << " \n"[i == n];
    return 0;
}
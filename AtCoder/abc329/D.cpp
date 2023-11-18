#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cerr << #x << " is " << x << endl
typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 5;

int n, m;
int a[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    vector<int> idx(n + 1);
    for (int i = 1; i <= m; ++i) {
        cin >> a[i];
    }
    int ma = 0, id = 0;
    for (int i = 1; i <= m; ++i) {
        idx[a[i]]++;
        if (idx[a[i]] > ma) {
            ma = idx[a[i]];
            id = a[i];
        }
        else if (idx[a[i]] == ma) {
            id = min(a[i], id);
        }
        cout << id << "\n";
    }
    return 0;
}
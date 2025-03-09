#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define debug(x) cerr << #x << " is " << x << endl
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 2; i < n; i++) {
        if (a[i] == a[i-1] && a[i] == a[i-2]) {
            cout << "Yes\n";
            exit(0);
        }
    }
    cout << "No\n";
    return 0;
}
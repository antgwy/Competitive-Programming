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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll sum = accumulate(a.begin(), a.end(), 0ll);
    if (sum < k && k <= 0) { cout << "No\n"; exit(0); }
    cout << "Yes\n";
    sort(a.begin(), a.end());
    if (k <= 0) {
        reverse(a.begin(), a.end());
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];
    }
    return 0;
}
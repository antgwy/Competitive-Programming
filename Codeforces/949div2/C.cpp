#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
#define debug(x) cerr << #x << " is " << x << endl
typedef pair<int, int> pii;
const int INF = 1e9 + 1;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), vec;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] != -1) {
            vec.push_back(i);
        }
    }

    if (!vec.size()) {
        for (int i = 0; i < n; i++) {
            cout << (i % 2 + 1) << " \n"[i == n - 1];
        }
        return;
    }
    for (int i = vec.front() - 1; i >= 0; i--) {
        a[i] = a[i+1] == 1 ? 2 : a[i+1] / 2;
    }
    for (int i = vec.back() + 1; i < n; i++) {
        a[i] = a[i-1] == 1 ? 2 : a[i-1] / 2;
    }
    for (int i = 0; i < (int)vec.size() - 1; i++) {
        int l = vec[i], r = vec[i+1];
        while (l + 1 < r) {
            if (a[l] > a[r]) {
                a[l+1] = a[l] == 1 ? 2 : a[l] / 2;
                l++;
            }
            else {
                a[r-1] = a[r] == 1 ? 2 : a[r] / 2;
                r--;
            }
        }
        if (a[l] != a[r] / 2 && a[r] != a[l] / 2) {
            cout << "-1\n"; 
            return;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];
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
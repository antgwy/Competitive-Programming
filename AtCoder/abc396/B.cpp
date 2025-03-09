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
    int q;
    cin >> q;
    vector<int> stk(100);
    while (q--) {
        int c, x;
        cin >> c;
        if (c == 1) {
            cin >> x;
            stk.push_back(x);
            continue;
        }
        cout << stk.back() << "\n";
        stk.pop_back();
    }
    return 0;
}
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
    int tri[7] = {1};
    for (int i = 1; i <= 6; i++) tri[i] = tri[i-1] * 3;

    auto get = [&](auto &&self, int x, int y, int l) {
        if (!l) return '#';
        if (x / tri[l-1] == 1 && y / tri[l-1] == 1) return '.';
        return self(self, x % tri[l-1], y % tri[l-1], l - 1);
    };
    
    for (int i = 0; i < tri[n]; i++) {
        for (int j = 0; j < tri[n]; j++) {
            cout << get(get, i, j, n);
        }
        cout << "\n";
    }
    return 0;
}
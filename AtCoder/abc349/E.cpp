#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cerr << #x << " is " << x << endl
typedef long long ll;
typedef pair<int, int> pii;
const ll INF = 1e18;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> a(9);
    for (int i = 0; i < 9; ++i) cin >> a[i];
    vector<vector<int> > lines = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        {0, 4, 8},
        {2, 4, 6}
    };
    
    auto f = [&](auto self, int turn, vector<int> &s) {
        for (auto &l : lines) {
            if (s[l[0]] && s[l[0]] == s[l[1]] && s[l[1]] == s[l[2]])
                return (s[l[0]] == 1 ? INF : -INF);
        }
        if (turn == 9) {
            ll s1 = 0, s2 = 0;
            for (int i = 0; i < 9; ++i) {
                if (s[i] == 1) s1 += a[i];
                else if (s[i] == 2) s2 += a[i];
            }
            return s1 - s2;
        } 
        if (turn % 2 == 0) {
            ll res = -INF;
            for (int i = 0; i < 9; ++i) {
                if (!s[i]) {
                    vector<int> t = s;
                    t[i] = 1;
                    res = max(res, self(self, turn + 1, t));
                }
            }
            return res;
        }
        else {
            ll res = INF;
            for (int i = 0; i < 9; ++i) {
                if (!s[i]) {
                    vector<int> t = s;
                    t[i] = 2;
                    res = min(res, self(self, turn + 1, t));
                }
            }
            return res;
        }
    };

    vector<int> s(9, 0);
    cout << (f(f, 0, s) > 0 ? "Takahashi" : "Aoki") << "\n";
    return 0;
}
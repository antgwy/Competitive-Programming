/*
https://codeforces.com/contest/1884/problem/C
Let x be the position of the maximum element in the array a in the optimal answer. 
Notice that in this case, we can select all the segments where l≤x≤r, 
because if the position of the minimum element is outside of this segment, 
we increase the answer by +1, and if it is inside, we do not worsen the answer.
From this, it follows that the minimum will either occur at position 1 or at position m.
*/
#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << " is " << x << endl
typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;

int t, n, m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<int> l(n+1), r(n+1);
        for (int i = 1; i <= n; ++i) {
            cin >> l[i] >> r[i];
        }
        auto solve = [&](int p) -> int {
            map<int, int> mp;
            for (int i = 1; i <= n; ++i) {
                if (l[i] <= p && p <= r[i]) continue;
                mp[l[i]-1]++;
                mp[r[i]]--;
            }
            int sum = 0, res = 0;
            for (auto [_, x] : mp) {
                sum += x;
                res = max(res, sum);
            }
            return res;
        };
        cout << max(solve(1), solve(m)) << "\n";
    }
    return 0;
}

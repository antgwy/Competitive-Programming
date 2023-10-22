/*
https://codeforces.com/contest/1884/problem/A
Let y be the answer to the problem. Note that y−x ≤ 18 and 
the problem can be solved by brute force. 
*/
#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << " is " << x << endl
typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;

int get(int x) {
    int res = 0;
    while (x) {
        res += x % 10;
        x /= 10;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int x, k;
        cin >> x >> k;
        while (get(x) % k != 0) {
            x++;
        }
        cout << x << "\n";
    }
    return 0;
}

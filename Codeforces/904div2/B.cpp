/*
https://codeforces.com/contest/1884/problem/B
If there are a digit with 1 in the k smallest digits, you can shift them all to the k
rightmost position to make a multiple of 2^{k−a}. Try for all k
, utilizing prefix sum to not make time complexity O(n^2). Time complexity O(n)

*/
#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << " is " << x << endl
typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const int N = 1e5 + 10;

int t, n;
int cnt, p[N], sum[N];
string str;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> str;
        reverse(str.begin(), str.end());
        cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (str[i] == '1') {
                p[++cnt] = i + 1;
                p[cnt] -= cnt;    
            }
        }
        p[cnt+1] = 0;
        for (int i = 1; i <= cnt; ++i) sum[i] = sum[i-1] + p[i];
        int cur = 1;
        // ll ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (i > n - cnt) { cout << "-1 "; continue; }
            cur = lower_bound(p + 1, p + cnt + 1, i) - p;
            /*while (p[cur] <= i + cur && cur <= cnt) {
                cur++;
            }
            for (int j = cur - 1; j >= 1; --j) {
                ans += 1ll * (i - p[j]);
            }*/
            cout << 1ll * (cur - 1) * i - sum[cur-1] << " ";
        }  
        cout << "\n";
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cerr << #x << " is " << x << endl
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 5;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(N);
    int l = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[l];
        l++;
        while (l > 1) {
            if (a[l-2] == a[l-1]) {
                a[l-2]++;
                l--;
            }
            else break;
        }
    }
    cout << l << "\n";
    return 0;
}
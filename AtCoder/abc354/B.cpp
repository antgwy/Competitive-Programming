#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cerr << #x << " is " << x << endl
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<string> s(n);
    int x, sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> s[i] >> x;
        sum += x;
    }
    sort(s.begin(), s.end());
    cout << s[sum%n] << "\n";
    return 0;
}
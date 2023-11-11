#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cerr << #x << " is " << x << endl
typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s, ans;
    cin >> s;
    for (auto c : s) {
        ans += c;
        if (ans.size() >= 3 && ans.substr(ans.size() - 3) == "ABC") ans.erase(ans.end() - 3, ans.end());
    }
    cout << ans << "\n";
    return 0;
}
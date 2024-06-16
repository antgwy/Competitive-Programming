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
    string s;
    cin >> s;
    int u = 0;
    for (char c : s) u += (isupper(c) != 0);
    if (2 * u > (int)s.size()) {
        for (auto& c : s) c = toupper(c);
    }
    else {
        for (auto& c : s) c = tolower(c);
    }
    cout << s << "\n";
    return 0;
}
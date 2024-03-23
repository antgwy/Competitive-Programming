#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cerr << #x << " is " << x << endl
typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;

bool check(string s) {
    int n = s.length();
    if (s[0] != '<' || s[n-1] != '>') return false;
    for (int i = 1; i < n - 1; ++i) {
        if (s[i] != '=') return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string str;
    cin >> str;
    if (check(str)) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}
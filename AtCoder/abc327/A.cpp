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
    int n, f = 0; 
    string s;
    cin >> n >> s;
    for (int i = 0; i < n - 1; ++i) {
    	if (s.substr(i, 2) == "ab" || s.substr(i, 2) == "ba") { f = 1; break; }
    }
    if(f) cout << "Yes\n";
    else cout << "No\n";
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cerr << #x << " is " << x << endl
typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;

ll qpow(ll a, ll x) {
	ll res = 1;
	for (; x; x >>= 1, a *= a)
		if (x & 1) res *= 1ll * a;
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
    cin.tie(0);
    ll b;
    cin >> b;
    for (ll a = 1; qpow(a, a) <= b; ++a) {
    	if (qpow(a, a) == b) {
    		cout << a << "\n";
    		exit(0);
    	}
    }
	cout << "-1\n";
	return 0;
}
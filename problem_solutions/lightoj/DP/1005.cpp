#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

#define MAX_N 31

ll ncr[MAX_N][MAX_N];
 
void solve() {
	int n, k;
	scanf(" %d %d", &n, &k);

	ll res = ncr[n][k];

	for (int i = n - k + 1; i <= n; ++i) {
		res *= i;
	}

	printf("%lld\n", res);
	
}
 
int main() {
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	#endif

	memset(ncr, 0, sizeof ncr);
	ncr[0][0] = 1;
	for (int i = 1; i < MAX_N; ++i) {
		for (int j = 0; j <= i; ++j) {
			ncr[i][j] = ncr[i - 1][j] + ncr[i - 1][j - 1];
		}
	}

	int t;
	scanf(" %d", &t);

	for (int i = 1; i <= t; ++i) {
		printf("Case %d: ", i);
		solve();
	}
}
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
void solve() {
	int n;
	scanf(" %d", &n);
	ll grid[2*n-1][n];

	memset(grid, 0 ,sizeof grid);

	for (int i = 0; i < 2*n-1; ++i) {
		for (int j = 0; j < i+1 - 2*max(0, i-n+1); ++j) {
			scanf(" %lld", &grid[i][j]);
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i+1 - 2*max(0, i-n+1); ++j) {
			ll add = 0;
			if (i) add = max(add, grid[i - 1][j]);
			if (i && j) add = max(add, grid[i - 1][j - 1]);
			grid[i][j] += add;
		}
	}
	for (int i = n; i < 2*n-1; ++i) {
		for (int j = 0; j < i+1 - 2*max(0, i-n+1); ++j) {
			ll add = 0;
			if (i) add = max(add, grid[i - 1][j]);
			if (i) add = max(add, grid[i - 1][j + 1]);
			grid[i][j] += add;
		}
	}

	printf("%lld\n", grid[2*n-2][0]);
}
 
int main() {
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif

	int t;
	scanf(" %d", &t);

	for (int i = 1; i <= t; ++i) {
		printf("Case %d: ", i);
		solve();
	}
}
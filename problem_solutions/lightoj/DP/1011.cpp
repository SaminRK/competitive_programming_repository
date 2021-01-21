#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/**
	state: mask
	01110001...
	1 in i-th place: some man has married i-th woman
	0 in i-th place: the i-th woman is not yet married

*/

int n;
vector<vector<int> > score;
vector<int> max_scores;

int calc(int man, int mask) {
	if (man >= n) return 0;
	if (max_scores[mask] != -1) return max_scores[mask];

	for (int i = 0; i < n; ++i) {
		if ((mask & (1<<i)) == 0) {
			max_scores[mask] = max(max_scores[mask], score[man][i] + calc(man+1, mask | (1<<i)));
		}
	}

	return max_scores[mask];
	
}

void solve() {
	
	scanf(" %d", &n);
	score.resize(n);
	for (int i = 0; i < n; ++i) score[i].resize(n);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf(" %d", &score[i][j]);
		}
	}

	max_scores.assign(1<<n , -1);

	int res = calc(0, 0);

	printf("%d\n", res);
	
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	#endif
	
	int t;
	scanf(" %d", &t);

	for (int i = 1; i <= t; ++i) {
		printf("Case %d: ", i);
		solve();
	}
}
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

/**
	ACGT
	ACGTGCGT
	ACCGTGC
	ACGCCGT

	1 1 1 1 1 1 ...
	1 1 1 1 1 2 ...
	1 1 2 2 3 3 ...
	1 1 1 3 4 4 ...
*/

int char2int(char c) {
	if (c == 'A') return 1;
	else if (c == 'G') return 2;
	else if (c == 'T') return 3;
	else if (c == 'C') return 4;

	return 0;
}

 
void solve() {
	int n;
	scanf(" %d", &n);
	vector<string> S(n);
	int m = 0;
	for (int i = 0; i < n; ++i) {
		cin >> S[i];
		m = max(m, (int)S[i].length());
	}
	vector<vector<int> > prefix_groups(m);
	for (int l = 0; l < m; ++l) prefix_groups[l].resize(n);

	ll res = 0;
	for (int l = 0; l < m; ++l) {
		for (int i = 0; i < n; ++i) {
			prefix_groups[l][i] = ((int)S[i].size() > l ? char2int(S[i][l]) : 0);
			if (l) {
				prefix_groups[l][i] += prefix_groups[l-1][i] * 5;
			}
		}
		
		// compaction
		int cur = 0;
		unordered_map<int,int> m;
		for (int i = 0; i < n; ++i)	{
			if (m.count(prefix_groups[l][i]) == 0) {
				m[prefix_groups[l][i]] = cur++;
			}
			prefix_groups[l][i] = m[prefix_groups[l][i]];
		}
		vector<int> fre(n);
		for (int i = 0; i < n; ++i)
			if ((int)S[i].size() > l)
				fre[prefix_groups[l][i]]++;

		for (int i = 0; i < n; ++i)	res = max(res, (ll)fre[i] * (l+1));

	}

	printf("%lld\n", res);

	// for (int i = 0; i < n; ++i) {
	// 	for (int l = 0; l < m; ++l) {
	// 		printf("%d ", prefix_groups[l][i]);
	// 	}
	// 	printf("\n");
	// }
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
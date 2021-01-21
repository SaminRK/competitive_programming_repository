#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int INF = 1e9;

int n, m;
vector<vector<int> > adj_list;
vector<int> dist;
priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
vector<vector<int> > closest(2); // state: (move2taken, node)

int dfs(int u, int move2taken) {

	// printf("at node %d move taken %d\n", u, move2taken);
	
	if (closest[move2taken][u] != -1) return closest[move2taken][u];

	closest[move2taken][u] = dist[u];

	for (int i = 0; i < (int)adj_list[u].size(); ++i) {
		int v = adj_list[u][i];
		if (move2taken) {
			if (dist[v] > dist[u]) {
				closest[1][u] = min(closest[1][u], dfs(v, 1));
			}
		} else {
			if (dist[v] > dist[u]) {
				closest[0][u] = min(closest[0][u], dfs(v, 0));	
				closest[0][u] = min(closest[0][u], dfs(v, 1));
			} else {
				closest[0][u] = min(closest[0][u], dfs(v, 1));
			}
		}
	}

	return closest[move2taken][u];
}

void solve() {
	
	scanf(" %d %d", &n, &m);
	adj_list.clear();
	adj_list.resize(n);
	for (int i = 0; i < m; ++i) {
		int u, v;
		scanf(" %d %d", &u, &v);
		--u, --v;
		adj_list[u].push_back(v);
	}

	int s = 0;

	dist.assign(n, INF);
	dist[s] = 0;
	
	while (!pq.empty()) pq.pop();
	pq.push({0, s});

	while (!pq.empty()) {
		auto p = pq.top(); pq.pop();
		int d = p.first, u = p.second;
		if (d > dist[u]) continue;

		for (int i = 0; i < (int)adj_list[u].size(); ++i) {
			int v = adj_list[u][i];
			if (dist[v] > dist[u] + 1) {
				dist[v] = dist[u] + 1;
				pq.push({dist[v], v});
			}
		}
	}

	for (int i = 0; i < 2; ++i) closest[i].assign(n, -1);
	closest[0][0] = closest[1][0] = 0;

	for (int i = 1; i < n; ++i) dfs(i, 0);

	// printf("dist\n");
	// for (int i = 0; i < n; ++i) {
	// 	printf("%d ", dist[i]);
	// }
	// printf("\n");

	// printf("closest\n");
	for (int i = 0; i < n; ++i) {
		printf("%d ", closest[0][i]);
	}
	printf("\n");
	


}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	#endif
	
	int t;
	scanf(" %d", &t);

	while (t--) {
		solve();
	}
}
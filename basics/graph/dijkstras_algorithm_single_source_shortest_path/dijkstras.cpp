#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;

int main() {

	freopen("in.txt", "r", stdin);
	
	// taking graph as input
	int n, m, s;
	scanf(" %d %d %d", &n, &m, &s);
	vector<vector<pair<int,int> > > adj_list(n);
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		scanf(" %d %d %d", &u, &v, &w);
		adj_list[u].push_back({v, w});
	}

	vector<int> dist(n, INF);
	dist[s] = 0;
	priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
	pq.push({0, s});

	while (!pq.empty()) {
		auto p = pq.top(); pq.pop();
		int d = p.first, u = p.second;
		if (d > dist[u]) continue; // important check because of lazy update

		for (int i = 0; i < (int)adj_list[u].size(); ++i) {
			auto e = adj_list[u][i];
			int v = e.first, w = e.second;
			if (dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				pq.push({dist[v], v});
			}
		}
	}

	// outputting distances
	for (int i = 0; i < n; ++i) {
		printf("%d\n", dist[i]);
	}
}
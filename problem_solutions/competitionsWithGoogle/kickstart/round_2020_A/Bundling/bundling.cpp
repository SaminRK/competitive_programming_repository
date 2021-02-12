#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct node {
	int next[26];
	int num = 0;

	node() {
		fill(begin(next), end(next), -1);
	}
};

vector<node> trie(1);

void insert_string(const string & s) {
	int u = 0;
	for (int i = 0; i < (int)s.length(); ++i) {
		int c = s[i] - 'A';
		if (trie[u].next[c] == -1) {
			trie[u].next[c] = (int) trie.size();
			trie.emplace_back();
		}
		u = trie[u].next[c];
		trie[u].num++;
	}
}

void solve() {
	trie.clear();
	trie.resize(1);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		insert_string(s);
	}
	ll res = 0;
	for (int i = 0; i < (int) trie.size(); ++i) {
		res += trie[i].num/k;
	}
	printf("%lld\n", res);

}


int main() {
	freopen("in.txt", "r", stdin);

	int t;
	scanf(" %d", &t);

	for (int i = 1; i <= t; ++i) {
		printf("Case #%d: ", i);
		solve();
	}
}
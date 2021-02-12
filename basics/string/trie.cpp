#include <bits/stdc++.h>
using namespace std;

struct node {
	int next[26];
	bool leaf = false;

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
	}
	trie[u].leaf = true;
}


int main() {
	

}
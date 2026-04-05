/*
Problem: P3605 Promotion Counting
Source: https://www.luogu.com.cn/problem/P3605
Training List: https://www.luogu.com.cn/training/9391
Topic: Data Structures
Subtopic: binary-indexed-tree
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>>g;
vector<int>dfn, siz;
int timer = 0;
void dfs(int u) {
	dfn[u] = ++timer;
	siz[u] = 1;
	for (int son : g[u]) {
		dfs(son);
		siz[u] += siz[son];
	}
}

struct BIT {
	vector<int> tree;
	int len;

	BIT(int n) : len(n) { tree.assign(n + 1, 0); }
	int lowbit(int x) { return x & (-x); }

	void add(int x, int delta) {
		for (int i = x; i <= len; i += lowbit(i))
			tree[i] += delta;
	}

	int sum(int x) {
		int res = 0;
		for (int i = x; i > 0; i -= lowbit(i))
			res += tree[i];
		return res;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	vector<int>p(n + 1);
	for (int i = 1; i <= n; i++)cin >> p[i];

	g.resize(n + 1); dfn.resize(n + 1); siz.resize(n + 1);
	for (int i = 2; i <= n; i++) {
		int fa; cin >> fa;
		g[fa].push_back(i);
	}
	dfs(1);

	vector<int>ord(n);
	for (int i = 0; i < n; i++) ord[i] = i + 1;
	sort(ord.begin(), ord.end(), [&](int a, int b) {return p[a] > p[b]; });

	vector<int> ans(n + 1);
	BIT bit(n);

	for (int i = 0; i < n; i++) {
		int u = ord[i];
		ans[u] = bit.sum(dfn[u] + siz[u] - 1) - bit.sum(dfn[u] - 1);
		bit.add(dfn[u], 1);
	}
	for (int i = 1; i <= n; i++)cout << ans[i] << "\n";

	return 0;
}


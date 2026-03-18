/*
Problem: P2024 Food Chain
Source: https://www.luogu.com.cn/problem/P2024
Training List: https://www.luogu.com.cn/training/9391
Topic: Data Structures
Subtopic: disjoint-set-union
*/
#include<iostream>
#include<vector>
using namespace std;
struct DSU {
	vector<int>fa;
	vector<int>sz;
	DSU(int n = 0) { init(n); }
	void init(int n) {
		fa.resize(n + 1);
		sz.assign(n + 1, 1);
		for (int i = 1; i <= n; i++) fa[i] = i;
	}
	int find(int a) {
		return fa[a] == a ? a : fa[a] = find(fa[a]);
	}
	int size(int a) {
		return sz[find(a)];
	}
	bool same(int a, int b) {
		return find(a) == find(b);
	}
	void unite(int a, int b) {
		a = find(a); b = find(b);
		if (a == b)return;
		if (sz[a] < sz[b])swap(a, b);
		fa[b] = a;
		sz[a] += sz[b];
	}
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k; cin >> n >> k;
	DSU dsu(3 * n);
	int res = 0;
	for (int i = 0; i < k; i++) {
		int f, x, y; cin >> f >> x >> y;
		if (x > n || y > n || (f == 2 && x == y)) { res++; continue; }
		if (f == 1) {
			if (dsu.same(x, y + n) || dsu.same(x, y + 2 * n)) res++;
			else dsu.unite(x, y), dsu.unite(x + n, y + n), dsu.unite(x + 2 * n, y + 2 * n);
		}
		else if (f == 2) {
			if (dsu.same(x, y) || dsu.same(x, y + n)) res++;
			else dsu.unite(x + n, y), dsu.unite(x, y + 2 * n), dsu.unite(x + 2 * n, y + n);
		}
	}
	cout << res;
	return 0;
}


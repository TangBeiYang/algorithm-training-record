/*
Problem: P1525 Prisoners
Source: https://www.luogu.com.cn/problem/P1525
Training List: https://www.luogu.com.cn/training/9391
Topic: Data Structures
*/
#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;
struct DSU {
	vector<int>fa;
	vector<int>si;
	DSU(int n = 0) { init(n); }
	void init(int n) {
		fa.resize(n + 1);
		si.assign(n + 1, 1);
		for (int i = 1; i <= n; i++)fa[i] = i;
	}
	int find(int u) {
		return fa[u] == u ? u : fa[u] = find(fa[u]);
	}
	int size(int u) {
		return si[find(u)];
	}
	bool same(int a, int b) {
		return find(a) == find(b);
	}
	void unite(int a, int b) {
		a = find(a); b = find(b);
		if (a == b)return;
		if (si[a] < si[b])swap(a, b);
		fa[b] = a;
		si[a] += si[b];
	}
};
int n, m;
vector<tuple<int, int, int>>peo;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	peo.resize(m);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		peo[i] = { c,a,b };
	}
	sort(peo.begin(), peo.end(), greater<tuple<int,int,int>>());
	DSU dsu(2 * n);
	for (int i = 0; i < m; i++) {
		auto [c, a, b] = peo[i];
		if (dsu.same(a, b)) {
			cout << c;
			return 0;
		}
		dsu.unite(a, b + n);
		dsu.unite(a + n, b);
	}
	cout << 0;
	return 0;
}


/*
Problem: P6111 MooTube
Source: https://www.luogu.com.cn/problem/P6111
Training List: https://www.luogu.com.cn/training/9391
Topic: Data Structures
*/
#include<iostream>
#include<tuple>
#include<algorithm>
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

	int n, q; cin >> n >> q;
	vector<tuple<int, int, int>>vid(n - 1);
	vector<tuple<int, int, int>>qus(q);
	vector<int>res(q);
	DSU dsu(n);
	for (int i = 0; i < n - 1; i++) {
		int a, b, r;
		cin >> a >> b >> r;
		vid[i] = { r,a,b };
	}
	sort(vid.begin(), vid.end(), greater<tuple<int, int, int>>());
	for (int i = 0; i < q; i++) {
		int k, v;
		cin >> k >> v;
		qus[i] = { k,v,i };
	}
	sort(qus.begin(), qus.end(), greater<tuple<int, int, int>>());
	int j = 0;
	for (int i = 0; i < q; i++) {
		auto [k, v, id] = qus[i];
		while (j < n - 1 && get<0>(vid[j]) >= k) {
			auto [r, a, b] = vid[j];
			dsu.unite(a, b);
			j++;
		}
		res[id] = dsu.size(v) - 1;
	}
	for (int i = 0; i < q; i++)cout << res[i] << "\n";
	return 0;
}


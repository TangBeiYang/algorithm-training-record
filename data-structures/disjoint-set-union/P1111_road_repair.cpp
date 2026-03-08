/*
Problem: P1111 Road Repair
Source: https://www.luogu.com.cn/problem/P1111
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
	vector<int>sz;
	DSU(int n = 0) { init(n); }
	void init(int n = 0) {
		fa.resize(n + 1);
		sz.assign(n + 1, 1);
		for (int i = 1; i <= n; i++)fa[i] = i;
	}
	int find(int x) {
		return fa[x] == x ? x : fa[x] = find(fa[x]);
	}
	int size(int x) {
		return sz[find(x)];
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

	int n, m; cin >> n >> m;
	DSU vill(n); bool flag = 1;
	vector<tuple<int, int, int>>temp(m);
	for (int i = 0; i < m; i++) {
		int a, b, t; cin >> a >> b >> t;
		temp[i] = { t,a,b };
	}
	sort(temp.begin(), temp.end());
	for (int i = 0; i < m; i++) {
		auto [t, a, b] = temp[i];
		vill.unite(a, b);
		if (vill.size(a) == n) {
			cout << t;
			flag = 0;
			break;
		}
	}
	if (flag)cout << -1;
	return 0;
}


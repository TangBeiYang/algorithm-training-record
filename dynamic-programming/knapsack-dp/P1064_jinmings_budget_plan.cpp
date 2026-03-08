/*
Problem: P1064 Jinmings Budget Plan
Source: https://www.luogu.com.cn/problem/P1064
Training List: https://www.luogu.com.cn/training/9391
Topic: Dynamic Programming - Knapsack DP
*/
#include<iostream>
#include<vector>
#include<tuple>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> m; n /= 10;
	vector<vector<pair<int, int>>>val(m);
	vector<tuple<int, int,int>>all(m);
	vector<int>index;
	for (int i = 0; i < m; i++) {
		int v, p, q; cin >> v >> p >> q;
		all[i] = { v / 10,v * p,q };
		if (q == 0) val[i].push_back({ v / 10,v * p }),
			        index .push_back(i);
	}
	for (int i = 0; i < m; i++) {
		auto [x, y, z] = all[i];
		if (z == 0)continue;
		val[z - 1].push_back({ x,y });
	}
	vector<int>dp_pre(n + 1, 0), dp_cur(n + 1, 0);
	int c = index.size();
	for (int i = 0; i < c; i++) {
		dp_cur = dp_pre;
		for (int j = n; j >= 0; j--) {
			auto [v, p] = val[index[i]][0];
			if (j < v)break;
			dp_cur[j] = max(dp_pre[j - v] + p, dp_pre[j]);
			int l = val[index[i]].size();
			if (l == 1)continue;
			auto [v1, p1] = val[index[i]][1];
			if (j >= v + v1)dp_cur[j] = max(dp_cur[j], dp_pre[j - v - v1] + p + p1);
			if (l == 2)continue;
			auto [v2, p2] = val[index[i]][2];
			if (j >= v + v2)dp_cur[j] = max(dp_cur[j], dp_pre[j - v - v2] + p + p2);
			if (j >= v + v1 + v2)dp_cur[j] = max(dp_cur[j], dp_pre[j - v - v1 - v2] + p + p1 + p2);
		}
		swap(dp_pre, dp_cur);
	}
	cout << dp_pre[n];
	return 0;
}


/*
Problem: P5905 Johnson All Pairs Shortest Path
Source: https://www.luogu.com.cn/problem/P5905
Training List: https://www.luogu.com.cn/training/9391
Topic: Graph Theory
Subtopic: shortest-path
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const long long INF = 4e18;
int main() {
    ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> m;
	vector<vector<pair<long long, long long>>>g(n + 1);
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({ v,w });
	}
	for (int i = 1; i <= n; i++)g[0].push_back({ i,0 });

	vector<long long> h(n + 1, INF);
	h[0] = 0;
	for (int i = 1; i <= n; i++) {
		bool updated = false;
		for (int u = 0; u <= n; u++) {
			for (auto [v, w] : g[u]) {
				if (h[u] != INF && h[v] > h[u] + w) {
					h[v] = h[u] + w;
					updated = true;
				}
			}
		}
		if (!updated) break;
	}
	for (int u = 0; u <= n; u++)
		for (auto [v, w] : g[u]) {
			if (h[u] != INF && h[v] > h[u] + w) {
				cout << -1;
				return 0;
			}
		}
	for (int u = 0; u <= n; u++)
		for (int i = 0; i < g[u].size(); i++)
			g[u][i].second = g[u][i].second + h[u] - h[g[u][i].first];

	for (int s = 1; s <= n; s++) {
		priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>>q;
		vector<long long>dist(n + 1, INF);
		vector<int>vis(n + 1, 0);
		q.push({ 0,s }); dist[s] = 0;

		while (!q.empty()) {
			auto [d, u] = q.top(); q.pop();
			if (vis[u])continue;
			vis[u] = 1;
			for (auto [v, w] : g[u]) {
				if (dist[v] > dist[u] + w) {
					dist[v] = dist[u] + w;
					q.push({ dist[v],v });
				}
			}
		}

		for (int i = 1; i <= n; i++) {
			if (dist[i] == 4e18)dist[i] = 1e9;
			else dist[i] = dist[i] - h[s] + h[i];
		}
		long long ans = 0;
		for (int j = 1; j <= n; j++) ans += j * dist[j];
		cout << ans << "\n";
	}

	return 0;
}


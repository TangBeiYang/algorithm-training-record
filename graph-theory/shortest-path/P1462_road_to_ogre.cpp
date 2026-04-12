/*
Problem: P1462 Road to Ogre
Source: https://www.luogu.com.cn/problem/P1462
Training List: https://www.luogu.com.cn/training/9391
Topic: Graph Theory
Subtopic: shortest-path
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n, m, b;
vector<int>mey;
vector<vector<pair<int, int>>>g;

bool check_d(int d) {
	if (d < mey[1] || d < mey[n])return 0;
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>>q;
	vector<long long>dist(n + 1, 4e18);
	vector<int>vis(n + 1, 0);
	q.push({ 0,1 }); dist[1] = 0;
	while (!q.empty()) {
		auto [s, u] = q.top(); q.pop();
		if (vis[u] || mey[u] > d)continue;
		vis[u] = 1;
		for (auto [v, w] : g[u]) {
			if (mey[v] > d)continue;
			if (dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				if (dist[v] <= b)q.push({ dist[v], v });
			}
		}
	}
	if (dist[n] <= b)return 1;
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> b;
	mey.resize(n + 1);
	int max_mey = 0;
	for (int i = 1; i <= n; i++) {
		cin >> mey[i]; 
		max_mey = max(mey[i], max_mey);
	}
	g.resize(n + 1);
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({ v,w });
		g[v].push_back({ u,w });
	}
	int left = 0, right = max_mey + 1;

	if (right == 1) {
		if (check_d(0)) { cout << 0; return 0; }
		else { cout << "AFK"; return 0; }
	}

	while (left + 1 < right) {
		int mid = (left + right) / 2;
		if (check_d(mid))right = mid;
		else left = mid;
	}

	if (right != max_mey + 1)cout << right;
	else cout << "AFK";

	return 0;
}


/*
Problem: P3371 Single Source Shortest Path
Source: https://www.luogu.com.cn/problem/P3371
Training List: https://www.luogu.com.cn/training/9391
Topic: Graph Theory
Subtopic: shortest-path
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int INF = 2147483647;
int main() {
    ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, s; cin >> n >> m >> s;
	vector<vector<pair<int, int>>>g(n + 1);
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({ v,w });
	}
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
                q.push({dist[v], v});
            }
        }
	}
	for (int i = 1; i <= n; i++) cout << dist[i] << " ";
	return 0;
}


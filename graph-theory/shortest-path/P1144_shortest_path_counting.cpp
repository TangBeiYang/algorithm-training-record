/*
Problem: P1144 Shortest Path Counting
Source: https://www.luogu.com.cn/problem/P1144
Training List: https://www.luogu.com.cn/training/9391
Topic: Graph Theory
Subtopic: shortest-path
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int MOD = 100003;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> m;
	vector<vector<int>>g(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	vector<int>ans(n + 1, 0), dist(n + 1,1e9);
	queue<int>q;
	q.push(1); dist[1] = 0; ans[1] = 1;

	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int v : g[u]) {
			if (dist[v] == 1e9) {
				ans[v] += ans[u];
				ans[v] %= MOD;
				dist[v] = dist[u] + 1;
				q.push(v);
			}
			else if (dist[v] == dist[u] + 1) {
				ans[v] += ans[u];
				ans[v] %= MOD;
			}
		}
	}

	for (int i = 1; i <= n; i++)cout << ans[i] << "\n";
	return 0;
}


//图的存储和遍历

//P2661 [NOIP 2015 提高组] 信息传递
/*#include<iostream>
#include<vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++)cin >> a[i];
	vector<int> vis(n + 1, 0);
	vector<int> in_round(n + 1, 0);
	vector<int> dep(n + 1, 0);

	int ans = 1e9;
	for (int i = 1; i <= n; i++) {
		if (vis[i])continue;
		int u = i;
		int step = 1;
		while (!vis[u]) {
			vis[u] = 1;
			dep[u] = step++;
			in_round[u] = i;
			u = a[u];
		}
		if (in_round[u] == i) {
			ans = min(ans, step - dep[u]);
		}
	}
	cout << ans;
	return 0;
}*/
//P2921 [USACO08DEC] Trick or Treat on the Farm G
/*#include<iostream>
#include<vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	vector<int>a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	vector<int>vis(n + 1, 0);
	vector<int>dep(n + 1);
	vector<int>in_round(n + 1);
	vector<int>ans(n + 1);
	vector<vector<int>>path(n + 1);
	for (int i = 1; i <= n; i++) {
		if (vis[i])continue;
		int u = i;
		int step = 0;
		do {
			path[i].push_back(u);
			vis[u] = 1;
			in_round[u] = i;
			dep[u] = step++;
			u = a[u];
		} while (!vis[u]);
		if (in_round[u] == i) {
			while (path[i].back() != u) {
				ans[path[i].back()] = step - dep[u];
				path[i].pop_back();
			}
			for (int j = 0; j < path[i].size(); j++) {
				ans[path[i][j]] = step - j;
			}
		}
		else {
			for (int j = 0; j < path[i].size(); j++) {
				ans[path[i][j]] = step - j + ans[u];
			}
		}
	}
	for (int i = 1; i <= n; i++)cout << ans[i] << "\n";
	return 0;
}*/

//最短路问题

//P3371 【模板】单源最短路径（弱化版）
/*#include<iostream>
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
}*/
//P5905 【模板】全源最短路（Johnson）
/*#include<iostream>
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
}*/
//P1144 最短路计数
/*#include<iostream>
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
}*/
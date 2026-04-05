/*
Problem: P2921 Trick or Treat on the Farm
Source: https://www.luogu.com.cn/problem/P2921
Training List: https://www.luogu.com.cn/training/9391
Topic: Graph Theory
Subtopic: traversal
*/
#include<iostream>
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
}


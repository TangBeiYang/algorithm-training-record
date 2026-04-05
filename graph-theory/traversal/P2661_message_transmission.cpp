/*
Problem: P2661 Message Transmission
Source: https://www.luogu.com.cn/problem/P2661
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
}


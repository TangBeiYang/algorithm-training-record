/*
Problem: P1902 Assassin Envoy
Source: https://www.luogu.com.cn/problem/P1902
Training List: https://www.luogu.com.cn/training/9391
Topic: Binary Search
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<vector<int>>p;
bool check_d(int d,int n, int m) {
	queue<pair<int, int>>q;
	vector<vector<bool>> vis(n, vector<bool>(m, 0));
	for (int i = 0; i < m; i++) { q.push({ 0,i }); vis[0][i] = 1; }
	int dx[] = { 0,0,1,-1 };
	int dy[] = { -1,1,0,0 };
	while (!q.empty()) {
		auto [x, y] = q.front(); q.pop();
		if (x == m - 1)return 1;
		for (int k = 0; k < 4; k++) {
			int xx = x + dx[k], yy = y + dy[k];
			if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
			if (p[xx][yy] > d || vis[xx][yy])continue;
			vis[xx][yy] = 1;
			q.push({ xx,yy });
		}
	}
	return 0;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> m;
	p.assign(n, vector<int>(m, 0));
	int mp = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> p[i][j];
			mp = max(mp, p[i][j]);
		}
	int left = 0, right = mp + 1;
	while (left + 1 < right) {
		int mid = (left + right) / 2;
		if (check_d(mid, n, m))right = mid;
		else left = mid;
	}
	cout << right;
	return 0;
}


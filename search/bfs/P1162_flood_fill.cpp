/*
Problem: P1162 Flood Fill
Source: https://www.luogu.com.cn/problem/P1162
Training List: https://www.luogu.com.cn/training/9391
Topic: Search
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<vector<int>>a;
queue<pair<int, int>>q;
void push_if_zero(int x, int y) {
	if (a[x][y] == 0) {
		a[x][y] = -1;
		q.push({ x,y });
	}
}
int main() {
	int n; cin >> n;
	a.assign(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)cin >> a[i][j];
	for (int i = 0; i < n; i++) {
		push_if_zero(i, 0);
		push_if_zero(0, i);
		push_if_zero(i, n-1);
		push_if_zero(n-1, i);
	}
	int dx[] = { 0,0,1,-1 };
	int dy[] = { -1,1,0,0 };
	while (!q.empty()) {
		auto [x, y] = q.front(); q.pop();
		for (int k = 0; k < 4; k++) {
			int xx = x + dx[k], yy = y + dy[k];
			if (xx < 0 || xx >= n || yy < 0 || yy >= n) continue;
			push_if_zero(xx, yy);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 0) a[i][j] = 2;
			else if (a[i][j] == -1) a[i][j] = 0; 
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << (j == n - 1 ? '\n' : ' ');
		}
	}
	return 0;
}


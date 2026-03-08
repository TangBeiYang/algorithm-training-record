/*
Problem: P1443 Knight Moves
Source: https://www.luogu.com.cn/problem/P1443
Training List: https://www.luogu.com.cn/training/9391
Topic: Search
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<vector<int>>a;
queue<pair<int, int>>q;
int main() {
	int n, m, x, y; cin >> n >> m >> x >> y;
	x--; y--;
	q.push({ x,y });
	a.assign(n, vector<int>(m, -1));
	int dx[] = { 1,1,-1,-1,2,2,-2,-2 };
	int dy[] = { -2,2,-2,2,1,-1,1,-1 };
	a[x][y] = 0;
	while (!q.empty()) {
		auto [xx, yy] = q.front(); q.pop();
		for (int k = 0; k < 8; k++) {
			int X = xx + dx[k]; int Y = yy + dy[k];
			if (X < 0 || X >= n || Y < 0 || Y >= m) continue;
			if (a[X][Y] != -1)continue;
			a[X][Y] = a[xx][yy] + 1;
			q.push({ X,Y });
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j] << (j == m - 1 ? '\n' : ' ');
		}
	}
	return 0;
}


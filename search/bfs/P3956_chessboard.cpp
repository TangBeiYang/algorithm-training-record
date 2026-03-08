/*
Problem: P3956 Chessboard
Source: https://www.luogu.com.cn/problem/P3956
Training List: https://www.luogu.com.cn/training/9391
Topic: Search
*/
#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
using namespace std;
vector<vector<int>>color;
vector<vector<vector<vector<int>>>>dist;
priority_queue<tuple<int, int, int, int, int>, vector<tuple<int, int, int, int, int>>, greater<tuple<int, int, int, int, int>>> q;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int m, n; cin >> m >> n;
	color.assign(m, vector<int>(m, -1));
	for (int i = 0; i < n; i++) {
		int x, y, c; cin >> x >> y >> c;
		color[--x][--y] = c;
	}
	const int INF = 1e9;
	dist.assign(m, vector<vector<vector<int>>>(m, vector<vector<int>>(2, vector<int>(2, INF))));
	q.push({ 0,0,0,color[0][0],0});
	dist[0][0][color[0][0]][0] = 0;
	int dx[] = { 0,0,1,-1 };
	int dy[] = { -1,1,0,0 };
	while (!q.empty()) {
		auto [d, x, y, col, magic] = q.top(); q.pop();
		if (d != dist[x][y][col][magic])continue;
		for (int k = 0; k < 4; k++) {
			int xx = x + dx[k], yy = y + dy[k];
			if (xx < 0 || xx >= m || yy < 0 || yy >= m) continue;
			if (color[xx][yy] == -1) {
				if (magic)continue;
				int nmagic = 1;
				if (d + 2 < dist[xx][yy][col][nmagic]) {
					dist[xx][yy][col][nmagic] = d + 2;
					q.push({ dist[xx][yy][col][nmagic],xx,yy,col,nmagic });
				}
				continue;
			}
			int w = (col == color[xx][yy] ? 0 : 1); int nmagic = 0;
			if (d + w < dist[xx][yy][color[xx][yy]][nmagic]) {
				dist[xx][yy][color[xx][yy]][nmagic] = d + w;
				q.push({ dist[xx][yy][color[xx][yy]][nmagic],xx,yy,color[xx][yy],nmagic });
			}
		}
	}
	int ans = INF;
	for (int col = 0; col < 2; col++)
		for (int used = 0; used < 2; used++)
			ans = min(ans, dist[m - 1][m - 1][col][used]);
	cout << (ans == INF ? -1 : ans);
	return 0;
}


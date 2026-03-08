//DFS深度优先搜索

//P1219[USACO1.5] 八皇后 Checker Challenge
/*#include<iostream>
#include<vector>
using namespace std;
int res = 0;
int printed = 0;
vector<int>pos;
vector<int>colused;
vector<int>diag1;
vector<int>diag2;
void find(int n,int row) {
	if (row == n + 1) {
		res++;
		if (printed < 3) {
			for (int i = 0; i < n; i++)cout << pos[i+1] << " ";
			cout << endl;
			printed++;
		}
		return;
	}
	for (int col = 1; col <= n; col++) {
		int d1 = row - col + n;
		int d2 = row + col;
		if (colused[col] || diag1[d1] || diag2[d2]) continue;
		pos[row] = col;
		colused[col] = diag1[d1] = diag2[d2] = 1;
		find(n, row + 1);
		colused[col] = diag1[d1] = diag2[d2] = 0;
	}
}
int main() {
	int n; cin >> n;
	pos.assign(n + 1, 0);
	colused.assign(n + 1, 0);
	diag1.assign(2 * n + 1, 0);
	diag2.assign(2 * n + 1, 0);
	find(n, 1);
	cout << res;
	return 0;
}*/
//P5194 [USACO05DEC] Scales S
/*#include<iostream>
#include<vector>
using namespace std;
long long c, maxw = 0;
vector<long long>w;
vector<long long>sum;
void dfs(int idx, long long cur) {
	if (cur > maxw) maxw = cur;
	if (idx < 0) return;
	if (cur + sum[idx] <= maxw) return;
	if (cur + w[idx] <= c)dfs(idx - 1, cur + w[idx]);
	dfs(idx - 1, cur);
}
int main() {
	int n; cin >> n >> c;
	long long temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (temp <= c)w.push_back(temp);
	}
	int m = (int)w.size();
	if (m == 0) { cout << 0 << "\n"; return 0; }
	sum.assign(m, 0);
	sum[0] = w[0];
	for (int i = 1; i < m; i++) sum[i] = sum[i - 1] + w[i];
	dfs(m - 1, 0);
	cout << maxw;
	return 0;
}*/
//P3958 [NOIP 2017 提高组] 奶酪
/*#include<iostream>
#include<vector>
#include<tuple>
using namespace std;
vector<tuple<long long, long long, long long>>loc;
vector<bool>pos;
int n, h, r; long long dd;
bool dfs(int u) {
	auto [x1, y1, z1] = loc[u];
	if (z1 + r >= h)return 1;
	pos[u] = 0;
	bool res = 0;
	for (int i = 1; i <= n; i++) {
		if (pos[i]) {
			auto [x2, y2, z2] = loc[i];
			long long xx = x1 - x2, yy = y1 - y2, zz = z1 - z2;
			if (xx * xx + yy * yy + zz * zz <= dd) 
				if (dfs(i))return 1;
		}
	}
	return 0;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T; cin >> T;
	for (int o = 0; o < T; o++) {
		cin >> n >> h >> r;
		loc.resize(n + 1); pos.assign(n + 1, 1);
		for (int i = 1; i <= n; i++) {
			long long x, y, z; cin >> x >> y >> z;
			loc[i] = { x,y,z };
		}
		dd = 4LL * r * r;
		int flag = 1;
		for (int i = 1; i <= n; i++) {
			auto [x, y, z] = loc[i];
			if (z <= r) {
				if (dfs(i)) {
					cout << "Yes\n";
					flag = 0;
					break;
				}
				pos[i] = 0;
			}
		}
		if (flag)cout << "No\n";
	}
}*/

//BFS广度优先搜索

//P1162 填涂颜色
/*#include<iostream>
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
}*/
//P1443 马的遍历
/*#include<iostream>
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
}*/
//P3956 [NOIP 2017 普及组] 棋盘
/*#include<iostream>
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
}*/
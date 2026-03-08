//P2678 [NOIP 2015 提高组] 跳石头
/*#include<iostream>
using namespace std;
bool check_d(int d, int n, int m, int ln[], int l) {
	int k = 0, left = 0, right = l;
	int i = 0, j = n - 1;
	while (1) {
		if (i == j) {
			if ((ln[i] - left < d) || (right - ln[j] < d)) {
				k++;
				if (right - left < d)k++;
			}
			break;
		}
		else if (j + 1 == i) {
			if (right - left < d)k++;
			break;
		}
		if (ln[i] - left < d)k++;
		else left = ln[i];
		if (right - ln[j] < d)k++;         //单向check更好
		else right = ln[j];
		i++; j--;
	}
	if (k > m)return 0;
	return 1;
}
int main() {
	int l, n, m;
	cin >> l >> n >> m;
	int ln[50000];
	for (int i = 0; i < n; i++)cin >> ln[i];
	int left = 0, right = l + 1;
	while (left + 1 < right) {
		int mid = (left + right) / 2;
		if (check_d(mid, n, m, ln, l))left = mid;
		else right = mid;
	}
	cout << left;
	return 0;
}*/
//P1902 刺杀大使
/*#include<iostream>
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
}*/
//P1314 [NOIP 2011 提高组] 聪明的质监员
/*#include<iostream>
#include<vector>
using namespace std;
long long s;
long long ans = (1LL << 62);
vector<int>w, v, li, ri;
int check_w(int W, int n, int m) {
	vector<long long> preCnt(n+1, 0), preSum(n+1, 0);
	for (int i = 1; i <= n; i++) {
		preCnt[i] = preCnt[i - 1];
		preSum[i] = preSum[i - 1];
		if (w[i - 1] >= W) {
			preCnt[i]++;
			preSum[i] += v[i - 1];
		}
	}
	long long Y = 0;
	for (int k = 0; k < m; k++) {
		int l = li[k], r = ri[k];
		long long cnt = preCnt[r] - preCnt[l - 1];
		long long sum = preSum[r] - preSum[l - 1];
		Y += cnt * sum;
	}
	ans = min(ans, abs(Y - s));
	return (Y >= s);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> m >> s;
	w.assign(n, 0); v.assign(n, 0);
	int wmax = 0, wmin = 1e9;
	for (int i = 0; i < n; i++) {
		cin >> w[i] >> v[i];
		wmax = wmax < w[i] ? w[i] : wmax;
		wmin = wmin > w[i] ? w[i] : wmin;
	}
	li.assign(m, 0); ri.assign(m, 0);
	for (int i = 0; i < m; i++)cin >> li[i] >> ri[i];
	int left = wmin - 1, right = wmax + 1;
	while (left + 1 < right) {
		int mid = (left + right) / 2;
		if (check_w(mid, n, m))left = mid;
		else right = mid;
	}
	check_w(left, n, m);
	check_w(right, n, m);
	cout << ans;
	return 0;
}*/
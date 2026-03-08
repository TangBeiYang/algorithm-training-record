/*
Problem: P3958 Cheese
Source: https://www.luogu.com.cn/problem/P3958
Training List: https://www.luogu.com.cn/training/9391
Topic: Search
*/
#include<iostream>
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
}


/*
Problem: P1855 Extracting KKKS C03
Source: https://www.luogu.com.cn/problem/P1855
Training List: https://www.luogu.com.cn/training/9391
Topic: Dynamic Programming - Knapsack DP
*/
#include<iostream>
#include<vector>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, t; cin >> n >> m >> t;
	vector<pair<int, int>>a(n);
	for (int i = 0; i < n; i++) {
		int ti, p; cin >> ti >> p;
		a[i] = { ti,p };
	}
	vector<vector<int>> f_prev(t + 1, vector<int>(m + 1, 0)),
		g_prev(t + 1, vector<int>(m + 1, 0)),
		f_cur(t + 1, vector<int>(m + 1, 0)),
		g_cur(t + 1, vector<int>(m + 1, 0));
	g_prev[0][0] = 0;
	for (int i = 0; i < n; i++) {
		for (int p = 0; p <= t; p++) {
			fill(f_cur[p].begin(), f_cur[p].end(), 0);
			fill(g_cur[p].begin(), g_cur[p].end(), 0);
		}
		g_cur[0][0] = 0;
		auto [ti, pr] = a[i];
		for (int s = t; s > 0; s--) {
			for (int j = m; j > 0; j--) {
				g_cur[s][j] = max(f_prev[s][j], g_prev[s][j]);
				if (s >= ti && j >= pr) f_cur[s][j] = max(f_prev[s - ti][j - pr] + 1, g_prev[s - ti][j - pr] + 1);
				else f_cur[s][j] = 0;
			}
		}
		swap(f_prev, f_cur); swap(g_prev, g_cur);
	}
	cout << max(f_prev[t][m], g_prev[t][m]);
	return 0;
}


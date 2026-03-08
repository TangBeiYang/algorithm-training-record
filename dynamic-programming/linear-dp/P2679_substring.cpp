/*
Problem: P2679 Substring
Source: https://www.luogu.com.cn/problem/P2679
Training List: https://www.luogu.com.cn/training/9391
Topic: Dynamic Programming - Linear DP
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int const MOD = 1000000007;
int main() {
	int n, m, k; cin >> n >> m >> k;
	string a, b; cin >> a; cin >> b;
	vector<vector<int>> f_prev(k + 1, vector<int>(m + 1, 0)),
		                g_prev(k + 1, vector<int>(m + 1, 0)),
		                f_cur (k + 1, vector<int>(m + 1, 0)),
		                g_cur (k + 1, vector<int>(m + 1, 0));
	g_prev[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int p = 0; p <= k; p++) {
			fill(f_cur[p].begin(), f_cur[p].end(), 0);
			fill(g_cur[p].begin(), g_cur[p].end(), 0);
		}
		g_cur[0][0] = 1;
		for (int p = 1; p <= k; p++) {
			for (int j = 1; j <= m; j++) {
				g_cur[p][j] = (g_prev[p][j] + f_prev[p][j]) % MOD;
				if (a[i - 1] == b[j - 1]) {
					f_cur[p][j] = ((long long)f_prev[p][j - 1] + f_prev[p - 1][j - 1] + g_prev[p - 1][j - 1]) % MOD;
				}
			}
		}
		swap(f_prev, f_cur); swap(g_prev, g_cur);
	}
	cout << ((f_prev[k][m] + g_prev[k][m]) % MOD);
	return 0;
}


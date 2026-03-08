/*
Problem: P1880 Stone Merging
Source: https://www.luogu.com.cn/problem/P1880
Training List: https://www.luogu.com.cn/training/9391
Topic: Dynamic Programming - Interval DP
*/
#include<iostream>
#include<vector>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	const long long INF = (1LL << 60);
	vector<vector<long long>>dpMax(2*n + 1, vector<long long>(2*n + 1, 0)),
		                     dpMin(2*n + 1, vector<long long>(2*n + 1, INF));
	vector<long long> a(2 * n + 1), pre(2 * n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i + n] = a[i];
	}
	for (int i = 1; i <= 2 * n; i++) pre[i] = pre[i - 1] + a[i];
	auto sum = [&](int l, int r) { return pre[r] - pre[l - 1]; };
	for (int i = 1; i <= 2*n; i++) { dpMax[i][i] = 0, dpMin[i][i] = 0; }
	for (int len = 2; len <= n; len++) {
		for (int l = 1; l + len - 1 <= 2*n; l++) {
			int r = l + len - 1;
			long long cost = sum(l, r);
			for (int k = l; k < r; k++) {
				dpMax[l][r] = max(dpMax[l][r], dpMax[l][k] + dpMax[k + 1][r] + cost);
				dpMin[l][r] = min(dpMin[l][r], dpMin[l][k] + dpMin[k + 1][r] + cost);
			}
		}
	}
	long long best = 0, worst = INF;
	for (int i = 1; i <= n; i++) {
		best = max(dpMax[i][i + n - 1], best);
		worst = min(dpMin[i][i + n - 1], worst);
	}
	cout << worst << "\n" << best << "\n";
	return 0;
}


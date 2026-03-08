/*
Problem: P1314 Smart Quality Inspector
Source: https://www.luogu.com.cn/problem/P1314
Training List: https://www.luogu.com.cn/training/9391
Topic: Binary Search
*/
#include<iostream>
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
}


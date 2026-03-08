/*
Problem: P3131 Subsequences Summing to Sevens
Source: https://www.luogu.com.cn/problem/P3131
Training List: https://www.luogu.com.cn/training/9391
Topic: Prefix Sum and Difference
*/
#include<iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	int id[50000];
	for (int i = 0; i < n; i++) cin >> id[i];
	long long sum[50001];
	sum[0] = 0;
	int modl[7], modr[7];
	for (int i = 1; i <= n; i++)sum[i] = (sum[i - 1] + id[i - 1]) % 7;
	int first[7], last[7];
	for (int k = 0; k < 7; k++) first[k] = -1, last[k] = -1;
	for (int i = 0; i <= n; i++) {
		int mod = sum[i];
		if (first[mod] == -1) first[mod] = i;
		last[mod] = i;
	}
	int res = 0;
	for (int mod = 0; mod < 7; mod++) {
		if (first[mod] != -1) res = max(res, last[mod] - first[mod]);
	}
	cout << res;
	return 0;
}


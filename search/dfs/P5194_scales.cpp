/*
Problem: P5194 Scales
Source: https://www.luogu.com.cn/problem/P5194
Training List: https://www.luogu.com.cn/training/9391
Topic: Search
*/
#include<iostream>
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
}


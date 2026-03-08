/*
Problem: P1216 Number Triangles
Source: https://www.luogu.com.cn/problem/P1216
Training List: https://www.luogu.com.cn/training/9391
Topic: Dynamic Programming - Linear DP
*/
#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>>dp;
int main() {
	int r; cin >> r;
	vector<vector<int>>a(r, vector<int>(r, -1));
	for (int i = 0; i < r; i++)
		for (int j = 0; j <= i; j++) cin >> a[i][j];
	dp.assign(r, vector<int>(r, -1));
	dp[0][0] = a[0][0];
	for(int i=1;i<r;i++)
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				dp[i][j] = dp[i - 1][j] + a[i][j];
			}
			else if (j == i) {
				dp[i][j] = dp[i - 1][j - 1] + a[i][j];
			}
			else {
				dp[i][j] = a[i][j] + max(dp[i - 1][j], dp[i - 1][j - 1]);
			}
		}
	int max = 0;
	for (int i = 0; i < r; i++)max = (max > dp[r - 1][i] ? max : dp[r - 1][i]);
	cout << max;
	return 0;
}


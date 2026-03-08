/*
Problem: P1095 Guardians Escape
Source: https://www.luogu.com.cn/problem/P1095
Training List: https://www.luogu.com.cn/training/9391
Topic: Dynamic Programming - Linear DP
*/
#include<iostream>
#include<vector>
using namespace std;
int main() {
	int m, s, t; cin >> m >> s >> t;
	int curs = 0, dp = 0;
	for (int i = 1; i <= t; i++) {
		if (m >= 10) { m -= 10; curs += 60; }
		else m += 4;
		dp = max(dp + 17, curs);
		if (dp > s) { cout << "Yes\n" << i; return 0; }
	}
	cout << "No\n" << dp;
	return 0;
}


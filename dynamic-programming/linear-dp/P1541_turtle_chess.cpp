/*
Problem: P1541 Turtle Chess
Source: https://www.luogu.com.cn/problem/P1541
Training List: https://www.luogu.com.cn/training/9391
Topic: Dynamic Programming - Linear DP
*/
#include<iostream>
#include<vector>
using namespace std;
int main() {
	int n, m; cin >> n >> m;
	vector<int>score(n, 0);
	vector<int>card(4, 0);
	for (int i = 0; i < n; i++)cin >> score[i];
	for (int j = 0; j < m; j++) {
		int temp; cin >> temp;
		card[temp - 1]++;
	}
	vector<vector<vector<vector<int>>>>dp(card[0] + 1, vector<vector<vector<int>>>(card[1] + 1, vector<vector<int>>(card[2] + 1, vector<int>(card[3] + 1, score[0]))));
	for (int i = 0; i <= card[0]; i++) {
		for (int j = 0; j <= card[1]; j++) {
			for (int k = 0; k <= card[2]; k++) {
				for (int l = 0; l <= card[3]; l++) {
					int pos = i + 2*j + 3*k + 4*l;
					int best = score[0];
					if (i > 0) best = max(best, dp[i - 1][j][k][l] + score[pos]);
					if (j > 0) best = max(best, dp[i][j - 1][k][l] + score[pos]);
					if (k > 0) best = max(best, dp[i][j][k - 1][l] + score[pos]);
					if (l > 0) best = max(best, dp[i][j][k][l - 1] + score[pos]);
					dp[i][j][k][l] = best;
				}
			}
		}
	}
	cout << dp[card[0]][card[1]][card[2]][card[3]];
	return 0;
}


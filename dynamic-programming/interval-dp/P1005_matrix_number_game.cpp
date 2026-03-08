/*
Problem: P1005 Matrix Number Game
Source: https://www.luogu.com.cn/problem/P1005
Training List: https://www.luogu.com.cn/training/9391
Topic: Dynamic Programming - Interval DP
*/
#include<iostream>
#include <string>
#include<vector>
using namespace std;

void print128(__int128 x) {
	if (x == 0) {
		cout << "0";
		return;
	}
	if (x < 0) {
		cout << "-";
		x = -x;
	}
	string s;
	while (x > 0) {
		s = char('0' + (x % 10)) + s;
		x /= 10;
	}
	cout << s;
}

__int128 read128() {
    string s;
    cin >> s;
    __int128 res = 0;
    bool flag = false;
    int start = 0;
    if (s[0] == '-') {
        flag = true;
        start = 1;
    }
    for (int i = start; i < s.size(); i++) res = res * 10 + (s[i] - '0');
    return flag ? -res : res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> m;
	vector<vector<__int128>>a(n, vector<__int128>(m));
	for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)a[i][j] = read128();
	__int128 ans = 0;
	for (int o = 0; o < n; o++) {
		vector<vector<__int128>>dp(m + 1, vector<__int128>(m + 1));
		for (int i = 1; i <= m; i++)dp[i][i] = a[o][i - 1] << m;
		for (int len = 2; len <= m; len++) {
			for (int l = 1; l + len - 1 <= m; l++) {
				int r = l + len - 1;
				__int128 head, tail;
				head = a[o][l - 1] << (m - len + 1);
				tail = a[o][r - 1] << (m - len + 1);
				dp[l][r] = max(dp[l + 1][r] + head, dp[l][r - 1] + tail);
			}
		}
		ans += dp[1][m];
	}
	print128(ans);
	return 0;
}


/*
Problem: P1198 Maximum Number
Source: https://www.luogu.com.cn/problem/P1198
Training List: https://www.luogu.com.cn/training/9391
Topic: Data Structures
Subtopic: sparse-table
*/
#include<iostream>
#include<vector>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int m, d; cin >> m >> d;
	const int LOG = 21;
	vector<vector<int>>st(m + 1, vector<int>(LOG));
	vector<int>lg(m + 1);
	lg[1] = 0;
	for (int i = 2; i <= m; i++) lg[i] = lg[i / 2] + 1;
	int t = 0, len_st = 0;

	while (m--) {
		char flag; cin >> flag;

		if (flag == 'A') {
			long long n; cin >> n;
			int neww = (n + t) % d;
			len_st++;
			st[len_st][0] = neww;
			for (int j = 1; j <= lg[len_st]; j++) {
				st[len_st][j] = max(st[len_st][j - 1],
					                st[len_st - (1 << (j - 1))][j - 1]);
			}
		}

		else {
			int L; cin >> L;
			t = max(st[len_st][lg[L]],
				    st[len_st - L + (1 << lg[L])][lg[L]]);
			cout << t << "\n";
		}
	}
	return 0;
}


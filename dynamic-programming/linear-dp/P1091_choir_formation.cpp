/*
Problem: P1091 Choir Formation
Source: https://www.luogu.com.cn/problem/P1091
Training List: https://www.luogu.com.cn/training/9391
Topic: Dynamic Programming - Linear DP
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	int n; cin >> n;
	vector<int>a(n, 0);
	for (int i = 0; i < n; i++)cin >> a[i];
	vector<int>left;
	vector<int>l(n, 0);
	for (int k = 0; k < n; k++) {
		auto it = lower_bound(left.begin(), left.end(), a[k]);
		l[k] = it - left.begin() + 1;
		if (it == left.end())left.push_back(a[k]);
		else *it = a[k];
	}
	vector<int>right;
	vector<int>r(n, 0);
	for (int k = n - 1; k >= 0; k--) {
		auto it = lower_bound(right.begin(), right.end(), a[k]);
		r[k] = it - right.begin() + 1;
		if (it == right.end())right.push_back(a[k]);
		else *it = a[k];
	}
	int best = 0;
	for (int i = 0; i < n; i++) best = max(l[i] + r[i] - 1, best);
	cout << n - best;
	return 0;
}


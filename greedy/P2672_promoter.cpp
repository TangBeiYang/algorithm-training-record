/*
Problem: P2672 Promoter
Source: https://www.luogu.com.cn/problem/P2672
Training List: https://www.luogu.com.cn/training/9391
Topic: Greedy
*/
#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
using namespace std;
priority_queue<tuple<int, int>>house;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	vector<int>temp(n, 0);
	vector<int>S;
	vector<int>A;
	vector<int>sumA(n, 0);
	vector<int>Smax(n, 0);
	vector<int>best_afteri(n, 0);
	for (int i = 0; i < n; i++)cin >> temp[i];
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		house.push({ a,temp[i] });
	}
	while (!house.empty()) {
		auto [a, s] = house.top(); house.pop();
		S.push_back(s); A.push_back(a);
	}
	sumA[0] = A[0]; Smax[0] = S[0]; best_afteri[n - 1] = A[n - 1] + 2 * S[n - 1];
	for (int i = 1; i < n; i++) {
		sumA[i] = sumA[i - 1] + A[i];
		Smax[i] = max(Smax[i - 1], S[i]);
		best_afteri[n - 1 - i] = max(best_afteri[n - i], A[n - i] + 2 * S[n - i]);
	}
	for (int i = 0; i < n; i++) {
		int ans1 = sumA[i] + 2 * Smax[i];
		int temp = i == 0 ? 0 : sumA[i - 1];
		int ans2 = temp + best_afteri[i];
		cout << max(ans1, ans2) << endl;
	}
	return 0;
}


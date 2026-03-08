/*
Problem: P1020 Missile Interception
Source: https://www.luogu.com.cn/problem/P1020
Training List: https://www.luogu.com.cn/training/9391
Topic: Dynamic Programming - Linear DP
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int>a;
	int temp;
	while (cin >> temp) {
		a.push_back(temp);
		if (cin.peek() == '\n') {
			break;
		}
	}
	int n = a.size();
	vector<int>dp;
	for (int h : a) {
		auto it = upper_bound(dp.begin(), dp.end(), h, greater<int>());
		if (it == dp.end())dp.push_back(h);
		else *it = h;
	}
	cout << dp.size() << endl;
	vector<int>low;
	for (int h : a) {
		auto it = lower_bound(low.begin(),low.end(),h);
		if (it == low.end())low.push_back(h);
		else *it = h;
	}
	cout << low.size();
}


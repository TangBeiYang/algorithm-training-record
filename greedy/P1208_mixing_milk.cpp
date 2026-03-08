/*
Problem: P1208 Mixing Milk
Source: https://www.luogu.com.cn/problem/P1208
Training List: https://www.luogu.com.cn/training/9391
Topic: Greedy
*/
#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
using namespace std;
priority_queue<tuple<int, int>, vector<tuple<int, int>>, greater<tuple<int, int>>>milk;
int main() {
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int p, a; cin >> p >> a;
		milk.push({ p,a });
	}
	int res = 0, v = 0;
	while (!milk.empty()) {
		auto [p, a] = milk.top(); milk.pop();
		if (v + a < n) { 
			res += a * p;
			v += a;
		}
		else {
			res += (n - v) * p; 
			break;
		}
	}
	cout << res;
}


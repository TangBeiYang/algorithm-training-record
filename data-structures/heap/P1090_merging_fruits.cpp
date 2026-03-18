/*
Problem: P1090 Merging Fruits
Source: https://www.luogu.com.cn/problem/P1090
Training List: https://www.luogu.com.cn/training/9391
Topic: Data Structures
Subtopic: heap
*/
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	priority_queue<long long, vector<long long>, greater<long long>> q;
	long long res = 0;
	long long first, second;
	for (int i = 0; i < n; i++) {
		int temp; cin >> temp;
		q.push(temp);
	}
	while (q.size() > 1) {
		first = q.top(); q.pop();
		second = q.top(); q.pop();
		long long w = first + second;
		res += w;
		q.push(w);
	}
	cout << res;
	return 0;
}


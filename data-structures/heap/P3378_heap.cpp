/*
Problem: P3378 Heap
Source: https://www.luogu.com.cn/problem/P3378
Training List: https://www.luogu.com.cn/training/9391
Topic: Data Structures
Subtopic: heap
*/
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main() {
	priority_queue<int,vector<int>,greater<int>>q;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int f; cin >> f;
		if (f == 1) {
			int x; cin >> x;
			q.push(x);
		}
		if (f == 2) {
			int a = q.top();
			cout << a << "\n";
		}
		if (f == 3) {
			q.pop();
		}
	}
	return 0;
}


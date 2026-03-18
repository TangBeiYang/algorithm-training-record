/*
Problem: P1908 Inversion Pairs
Source: https://www.luogu.com.cn/problem/P1908
Training List: https://www.luogu.com.cn/training/9391
Topic: Data Structures
Subtopic: binary-indexed-tree
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct BIT {
	vector<int> tree;
	int len;

	BIT(int n) : len(n) { tree.assign(n + 1, 0); }
	int lowbit(int x) { return x & (-x); }

	void add(int x, int delta) {
		for (int i = x; i <= len; i += lowbit(i))
			tree[i] += delta;
	}

	int sum(int x) {
		int res = 0;
		for (int i = x; i > 0; i -= lowbit(i))
			res += tree[i];
		return res;
	}
};

int main() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	vector<int> b;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b.push_back(a[i]);
	}

	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());
	for (int i = 1; i <= n; i++) {
		int rk = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
		a[i] = rk;
	}

	BIT bit((int)b.size());
	long long res = 0;
	for (int i = 1; i <= n; i++) {
		res += (i - 1 - bit.sum(a[i]));
		bit.add(a[i], 1);
	}

	cout << res;
	return 0;
}


/*
Problem: P3374 Binary Indexed Tree 1
Source: https://www.luogu.com.cn/problem/P3374
Training List: https://www.luogu.com.cn/training/9391
Topic: Data Structures
Subtopic: binary-indexed-tree
*/
#include<iostream>
#include<vector>
using namespace std;
struct BIT {
	vector<long long>tree;
	int len;

	BIT(int n) :len(n) { tree.assign(n + 1, 0); }
	int lowbit(int n) {
		return n & (-n);
	}

	void init(vector<long long>& a) {
		for (int i = 1; i <= len; i++)
			add(i, a[i]);
	}

	void add(int x, long long delta) {
		for (int i = x; i <= len; i += lowbit(i))
			tree[i] += delta;
	}

	long long sum(int x) {
		int res = 0;
		for (int i = x; i > 0; i -= lowbit(i))
			res += tree[i];
		return res;
	}

	long long query(int l, int r) {
		return sum(r) - sum(l - 1);
	}
};
int main() {
	int n, m; cin >> n >> m;
	vector<long long>a(n + 1);
	BIT bit(n);

	for (int i = 1; i <= n; i++)cin >> a[i];
	bit.init(a);

	while (m--) {
		int flag; cin >> flag;
		if (flag == 1) {
			int x; long long k; cin >> x >> k;
			bit.add(x, k);
		}
		else {
			int x, y; cin >> x >> y;
			cout << bit.query(x, y) << "\n";
		}
	}
	
	return 0;
}


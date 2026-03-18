/*
Problem: P3368 Binary Indexed Tree 2
Source: https://www.luogu.com.cn/problem/P3368
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
		if (x > len)return;
		for (int i = x; i <= len; i += lowbit(i))
			tree[i] += delta;
	}

	long long sum(int x) {
		int res = 0;
		for (int i = x; i > 0; i -= lowbit(i))
			res += tree[i];
		return res;
	}
};
int main() {
	int n, m; cin >> n >> m;
	vector<long long>a(n + 1);
	vector<long long>diff(n + 1);
	BIT bit(n);

	for (int i = 1; i <= n; i++)cin >> a[i];
	diff[1] = a[1];
	for (int i = 2; i <= n; i++) diff[i] = a[i] - a[i - 1];
	bit.init(diff);

	while (m--) {
		int flag; cin >> flag;
		if (flag == 1) {
			int x, y; long long k; cin >> x >> y >> k;
			bit.add(x, k);
			bit.add(y + 1, -k);
		}
		else {
			int x; cin >> x;
			cout << bit.sum(x) << "\n";
		}
	}

	return 0;
}


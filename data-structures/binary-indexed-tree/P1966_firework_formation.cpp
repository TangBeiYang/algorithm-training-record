/*
Problem: P1966 Firework Formation
Source: https://www.luogu.com.cn/problem/P1966
Training List: https://www.luogu.com.cn/training/9391
Topic: Data Structures
Subtopic: binary-indexed-tree
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n; const int mod = 99999997;

void be_rk(vector<int>& m_rk, vector<int>& m) {
	sort(m_rk.begin(), m_rk.end());
	for (int i = 1; i <= n; i++) {
		int rk = lower_bound(m_rk.begin(), m_rk.end(), m[i]) - m_rk.begin() + 1;
		m[i] = rk;
	}
}

struct BIT {
	vector<long long> tree;
	int len;

	BIT(int n) : len(n) { tree.assign(n + 1, 0); }
	int lowbit(int x) { return x & (-x); }

	void add(int x, int delta) {
		for (int i = x; i <= len; i += lowbit(i))
			tree[i] += delta, tree[i] %= mod;
	}

	int sum(int x) {
		long long res = 0;
		for (int i = x; i > 0; i -= lowbit(i))
			res += tree[i], res %= mod;
		return res;
	}
};

int main() {
	cin >> n;
	vector<int>a(n + 1), b(n + 1),
		a_rk, b_rk,
		id(n + 1), ult(n + 1);
	for (int i = 1; i <= n; i++) { cin >> a[i]; a_rk.push_back(a[i]); }
	for (int i = 1; i <= n; i++) { cin >> b[i]; b_rk.push_back(b[i]); }
	
	be_rk(a_rk, a); be_rk(b_rk, b);

	for (int i = 1; i <= n; i++)id[b[i]] = i;
	for (int i = 1; i <= n; i++)ult[i] = id[a[i]];    

	BIT bit(n);

	long long res = 0;
	for (int i = 1; i <= n; i++) {
		res += (i - 1 - bit.sum(ult[i])), res %= mod;
		bit.add(ult[i], 1);
	}

	cout << res;
	return 0;
}


/*
Problem: P1226 Fast Power
Source: https://www.luogu.com.cn/problem/P1226
Training List: https://www.luogu.com.cn/training/9391
Topic: Divide and Conquer
*/
#include<iostream>
using namespace std;
long long ans(long long a, long long b, long long p) {
	if (b == 0)return 1;
	if (b % 2 == 0) {
		return ans(a * a % p, b / 2, p);
	}
	return ans(a, b - 1, p) * a % p;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long a, b, p; cin >> a >> b >> p;
	cout << a << "^" << b << " mod " << p << "=" << ans(a % p, b, p) % p;
}


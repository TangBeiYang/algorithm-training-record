/*
Problem: P4995 Jump Jump
Source: https://www.luogu.com.cn/problem/P4995
Training List: https://www.luogu.com.cn/training/9391
Topic: Greedy
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int h[300];
int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> h[i];
	sort(h, h + n);
	long long res = h[n - 1] * h[n - 1];
	int i = 0, j = n - 1;
	while (i < j) {
		res += (h[j] - h[i]) * (h[j] - h[i]);
		if (--j <= i)break;
		res += (h[j] - h[i]) * (h[j] - h[i]);
		i++;
	}
	cout << res;
	return 0;
}


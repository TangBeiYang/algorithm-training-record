/*
Problem: P2678 Jumping Stones
Source: https://www.luogu.com.cn/problem/P2678
Training List: https://www.luogu.com.cn/training/9391
Topic: Binary Search
*/
#include<iostream>
using namespace std;
bool check_d(int d, int n, int m, int ln[], int l) {
	int k = 0, left = 0, right = l;
	int i = 0, j = n - 1;
	while (1) {
		if (i == j) {
			if ((ln[i] - left < d) || (right - ln[j] < d)) {
				k++;
				if (right - left < d)k++;
			}
			break;
		}
		else if (j + 1 == i) {
			if (right - left < d)k++;
			break;
		}
		if (ln[i] - left < d)k++;
		else left = ln[i];
		if (right - ln[j] < d)k++;         //单向check更好
		else right = ln[j];
		i++; j--;
	}
	if (k > m)return 0;
	return 1;
}
int main() {
	int l, n, m;
	cin >> l >> n >> m;
	int ln[50000];
	for (int i = 0; i < n; i++)cin >> ln[i];
	int left = 0, right = l + 1;
	while (left + 1 < right) {
		int mid = (left + right) / 2;
		if (check_d(mid, n, m, ln, l))left = mid;
		else right = mid;
	}
	cout << left;
	return 0;
}


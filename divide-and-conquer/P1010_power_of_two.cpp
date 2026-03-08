/*
Problem: P1010 Power of Two
Source: https://www.luogu.com.cn/problem/P1010
Training List: https://www.luogu.com.cn/training/9391
Topic: Divide and Conquer
*/
#include<iostream>
#include<vector>
using namespace std;
void ans(int n) {
	vector<int>temp;
	if (n == 2) { cout << "2"; return; }
	if (n == 0) { cout << "0"; return; }
	while (n != 0) {
		temp.push_back(n % 2);
		n /= 2;
	}
	int l = temp.size();
	for (int i = l - 1; i >= 0; i--) {
		if (temp[i] == 0)continue;
		if (i < l - 1)cout << "+";
		if (i == 1) { cout << "2"; continue; }
		cout << "2("; ans(i); cout << ")";
	}
}
int main() {
	int n; cin >> n;
	ans(n);
	return 0;
}


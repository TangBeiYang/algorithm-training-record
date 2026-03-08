/*
Problem: P1981 Expression Evaluation
Source: https://www.luogu.com.cn/problem/P1981
Training List: https://www.luogu.com.cn/training/9391
Topic: Data Structures
*/
#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main() {
	stack<int>a;
	string temp; cin >> temp;
	int num = 0;
	for (int i = 0;; i++) {
		if (temp[i] == '\0') {
			a.push(num);
			break;
		}
		else if (temp[i] == '+') {
			a.push(num);
			num = 0;
		}
		else if (temp[i] == '*') {
			int x = a.top(); a.pop();
			int y = num; num = 0;
			a.push(x * y);
		}
		else {
			num = num * 10 + int(temp[i] - '0');
		}
	}
	int res = 0;
	while (!a.empty()) {
		int x = a.top(); a.pop();
		res += x;
	}
	int result[4] = { 0,0,0,0 };
	for (int i = 0; i < 4; i++) {
		result[i] = res % 10;
		res /= 10;
	}
	if (result[3] == 0) {
		if (result[2] == 0) {
			if (result[1] == 0) {
				cout << result[0];
			}
			else cout << result[1] << result[0];
		}
		else cout << result[2] << result[1] << result[0];
	}
	else cout << result[3] << result[2] << result[1] << result[0];
	return 0;
}


/*
Problem: P1449 Postfix Expression
Source: https://www.luogu.com.cn/problem/P1449
Training List: https://www.luogu.com.cn/training/9391
Topic: Data Structures
*/
#include<iostream>
#include<stack>
using namespace std;
int main() {
	stack<int>a;
	char temp; cin >> temp;
	int num = 0;
	while (temp != '@') {
		if (temp == '.') {
			a.push(num);
			num = 0;
		}
		else if (temp == '+') {
			int x = a.top(); a.pop();
			int y = a.top(); a.pop();
			a.push(x + y);
		}
		else if (temp == '-') {
			int x = a.top(); a.pop();
			int y = a.top(); a.pop();
			a.push(y - x);
		}
		else if (temp == '*') {
			int x = a.top(); a.pop();
			int y = a.top(); a.pop();
			a.push(x * y);
		}
		else if (temp == '/') {
			int x = a.top(); a.pop();
			int y = a.top(); a.pop();
			a.push(y / x);
		}
		else {
			num = num * 10 + int(temp - '0');
		}
		cin >> temp;
	}
	cout << a.top();
	return 0;
}


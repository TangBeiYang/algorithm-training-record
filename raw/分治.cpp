//P1226 【模板】快速幂
/*#include<iostream>
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
}*/
//P1010 [NOIP 1998 普及组] 幂次方
/*#include<iostream>
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
}*/
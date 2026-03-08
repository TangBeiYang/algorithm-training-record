//P1208 [USACO1.3] 混合牛奶 Mixing Milk
/*#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
using namespace std;
priority_queue<tuple<int, int>, vector<tuple<int, int>>, greater<tuple<int, int>>>milk;
int main() {
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int p, a; cin >> p >> a;
		milk.push({ p,a });
	}
	int res = 0, v = 0;
	while (!milk.empty()) {
		auto [p, a] = milk.top(); milk.pop();
		if (v + a < n) { 
			res += a * p;
			v += a;
		}
		else {
			res += (n - v) * p; 
			break;
		}
	}
	cout << res;
}*/
//P4995 跳跳！
/*#include<iostream>
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
}*/
//P2672 [NOIP 2015 普及组] 推销员
/*#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
using namespace std;
priority_queue<tuple<int, int>>house;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	vector<int>temp(n, 0);
	vector<int>S;
	vector<int>A;
	vector<int>sumA(n, 0);
	vector<int>Smax(n, 0);
	vector<int>best_afteri(n, 0);
	for (int i = 0; i < n; i++)cin >> temp[i];
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		house.push({ a,temp[i] });
	}
	while (!house.empty()) {
		auto [a, s] = house.top(); house.pop();
		S.push_back(s); A.push_back(a);
	}
	sumA[0] = A[0]; Smax[0] = S[0]; best_afteri[n - 1] = A[n - 1] + 2 * S[n - 1];
	for (int i = 1; i < n; i++) {
		sumA[i] = sumA[i - 1] + A[i];
		Smax[i] = max(Smax[i - 1], S[i]);
		best_afteri[n - 1 - i] = max(best_afteri[n - i], A[n - i] + 2 * S[n - i]);
	}
	for (int i = 0; i < n; i++) {
		int ans1 = sumA[i] + 2 * Smax[i];
		int temp = i == 0 ? 0 : sumA[i - 1];
		int ans2 = temp + best_afteri[i];
		cout << max(ans1, ans2) << endl;
	}
	return 0;
}*/

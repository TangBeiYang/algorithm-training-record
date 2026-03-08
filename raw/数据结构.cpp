//栈

//P1449 后缀表达式
/*#include<iostream>
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
}*/
//P1981 [NOIP 2013 普及组] 表达式求值
/*#include<iostream>
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
}*/

//并查集

//并查集模板：
/*#include<iostream>
#include<vector>
using namespace std;
struct DSU {
	vector<int>fa;
	vector<int>sz;
	DSU(int n = 0) { init(n); }
	void init(int n = 0) {
		fa.resize(n + 1);
		sz.assign(n + 1, 1);
		for (int i = 1; i <= n; i++)fa[i] = i;
	}
	int find(int x) {
		return fa[x] == x ? x : fa[x] = find(fa[x]);
	}
	int size(int x) {
		return sz[find(x)];
	}
	bool same(int a, int b) {
		return find(a) == find(b);
	}
	void unite(int a, int b) {
		a = find(a); b = find(b);
		if (a == b)return;
		if (sz[a] < sz[b])swap(a, b);
		fa[b] = a;
		sz[a] += sz[b];
	}
};*/
//P1111 修复公路
/*#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;
struct DSU {
	vector<int>fa;
	vector<int>sz;
	DSU(int n = 0) { init(n); }
	void init(int n = 0) {
		fa.resize(n + 1);
		sz.assign(n + 1, 1);
		for (int i = 1; i <= n; i++)fa[i] = i;
	}
	int find(int x) {
		return fa[x] == x ? x : fa[x] = find(fa[x]);
	}
	int size(int x) {
		return sz[find(x)];
	}
	bool same(int a, int b) {
		return find(a) == find(b);
	}
	void unite(int a, int b) {
		a = find(a); b = find(b);
		if (a == b)return;
		if (sz[a] < sz[b])swap(a, b);
		fa[b] = a;
		sz[a] += sz[b];
	}
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int n, m; cin >> n >> m;
	DSU vill(n); bool flag = 1;
	vector<tuple<int, int, int>>temp(m);
	for (int i = 0; i < m; i++) {
		int a, b, t; cin >> a >> b >> t;
		temp[i] = { t,a,b };
	}
	sort(temp.begin(), temp.end());
	for (int i = 0; i < m; i++) {
		auto [t, a, b] = temp[i];
		vill.unite(a, b);
		if (vill.size(a) == n) {
			cout << t;
			flag = 0;
			break;
		}
	}
	if (flag)cout << -1;
	return 0;
}*/
//奶酪
/*#include<iostream>
#include<vector>
#include<tuple>
using namespace std;
struct DSU {
	vector<int>fa;
	vector<int>sz;
	DSU(int n = 0) { init(n); }
	void init(int n = 0) {
		fa.resize(n + 1);
		sz.assign(n + 1, 1);
		for (int i = 0; i <= n; i++)fa[i] = i;
	};
	int find(int x) {
		return fa[x] == x ? x : fa[x] = find(fa[x]);
	}
	int size(int x) {
		return sz[find(x)];
	}
	bool same(int a, int b) {
		return find(a) == find(b);
	}
	void unite(int a, int b) {
		a = find(a); b = find(b);
		if (a == b)return;
		if (sz[a] < sz[b])swap(a, b);
		fa[b] = a;
		sz[a] += sz[b];
	}
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T; cin >> T;
	for (int o = 0; o < T; o++) {
		int n, h, r; cin >> n >> h >> r;
		vector<tuple<long long, long long, long long>>loc(n + 1);
		for (int i = 1; i <= n; i++) {
			long long x, y, z; cin >> x >> y >> z;
			loc[i] = { z,x,y };
		}
		DSU dsu(n + 1);
		int down = 0, up = n + 1; long long d = 2LL * r, dd = d * d;
		for (int i = 1; i <= n; i++) {
			auto [z, x, y] = loc[i];
			if (z <= r)dsu.unite(down, i);
			if (z + r >= h)dsu.unite(i, up);
		}
		for (int i = 1; i <= n; i++) {
			auto [z1, x1, y1] = loc[i];
			for (int j = i + 1; j <= n; j++) {
				auto [z2, x2, y2] = loc[j];
				long long xx = x1 - x2, yy = y1 - y2, zz = z1 - z2;
				if (xx * xx + yy * yy + zz * zz <= dd) dsu.unite(i, j);
			}
		}
		if (dsu.same(down, up))cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}*/
//P1525 [NOIP 2010 提高组] 关押罪犯
/*#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;
struct DSU {
	vector<int>fa;
	vector<int>si;
	DSU(int n = 0) { init(n); }
	void init(int n) {
		fa.resize(n + 1);
		si.assign(n + 1, 1);
		for (int i = 1; i <= n; i++)fa[i] = i;
	}
	int find(int u) {
		return fa[u] == u ? u : fa[u] = find(fa[u]);
	}
	int size(int u) {
		return si[find(u)];
	}
	bool same(int a, int b) {
		return find(a) == find(b);
	}
	void unite(int a, int b) {
		a = find(a); b = find(b);
		if (a == b)return;
		if (si[a] < si[b])swap(a, b);
		fa[b] = a;
		si[a] += si[b];
	}
};
int n, m;
vector<tuple<int, int, int>>peo;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	peo.resize(m);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		peo[i] = { c,a,b };
	}
	sort(peo.begin(), peo.end(), greater<tuple<int,int,int>>());
	DSU dsu(2 * n);
	for (int i = 0; i < m; i++) {
		auto [c, a, b] = peo[i];
		if (dsu.same(a, b)) {
			cout << c;
			return 0;
		}
		dsu.unite(a, b + n);
		dsu.unite(a + n, b);
	}
	cout << 0;
	return 0;
}*/
//P6111 [USACO18JAN] MooTube S
/*#include<iostream>
#include<tuple>
#include<algorithm>
#include<vector>
using namespace std;
struct DSU {
	vector<int>fa;
	vector<int>sz;
	DSU(int n = 0) { init(n); }
	void init(int n) {
		fa.resize(n + 1);
		sz.assign(n + 1, 1);
		for (int i = 1; i <= n; i++) fa[i] = i;
	}
	int find(int a) {
		return fa[a] == a ? a : fa[a] = find(fa[a]);
	}
	int size(int a) {
		return sz[find(a)];
	}
	bool same(int a, int b) {
		return find(a) == find(b);
	}
	void unite(int a, int b) {
		a = find(a); b = find(b);
		if (a == b)return;
		if (sz[a] < sz[b])swap(a, b);
		fa[b] = a;
		sz[a] += sz[b];
	}
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q; cin >> n >> q;
	vector<tuple<int, int, int>>vid(n - 1);
	vector<tuple<int, int, int>>qus(q);
	vector<int>res(q);
	DSU dsu(n);
	for (int i = 0; i < n - 1; i++) {
		int a, b, r;
		cin >> a >> b >> r;
		vid[i] = { r,a,b };
	}
	sort(vid.begin(), vid.end(), greater<tuple<int, int, int>>());
	for (int i = 0; i < q; i++) {
		int k, v;
		cin >> k >> v;
		qus[i] = { k,v,i };
	}
	sort(qus.begin(), qus.end(), greater<tuple<int, int, int>>());
	int j = 0;
	for (int i = 0; i < q; i++) {
		auto [k, v, id] = qus[i];
		while (j < n - 1 && get<0>(vid[j]) >= k) {
			auto [r, a, b] = vid[j];
			dsu.unite(a, b);
			j++;
		}
		res[id] = dsu.size(v) - 1;
	}
	for (int i = 0; i < q; i++)cout << res[i] << "\n";
	return 0;
}*/

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
//P2024 [NOI2001] 食物链
/*#include<iostream>
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

	int n, k; cin >> n >> k;
	DSU dsu(3 * n);
	int res = 0;
	for (int i = 0; i < k; i++) {
		int f, x, y; cin >> f >> x >> y;
		if (x > n || y > n || (f == 2 && x == y)) { res++; continue; }
		if (f == 1) {
			if (dsu.same(x, y + n) || dsu.same(x, y + 2 * n)) res++;
			else dsu.unite(x, y), dsu.unite(x + n, y + n), dsu.unite(x + 2 * n, y + 2 * n);
		}
		else if (f == 2) {
			if (dsu.same(x, y) || dsu.same(x, y + n)) res++;
			else dsu.unite(x + n, y), dsu.unite(x, y + 2 * n), dsu.unite(x + 2 * n, y + n);
		}
	}
	cout << res;
	return 0;
}*/

//二叉堆，完全二叉树

//P3378 【模板】堆
/*#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main() {
	priority_queue<int,vector<int>,greater<int>>q;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int f; cin >> f;
		if (f == 1) {
			int x; cin >> x;
			q.push(x);
		}
		if (f == 2) {
			int a = q.top();
			cout << a << "\n";
		}
		if (f == 3) {
			q.pop();
		}
	}
	return 0;
}*/
//P1090 [NOIP 2004 提高组] 合并果子
/*#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	priority_queue<long long, vector<long long>, greater<long long>> q;
	long long res = 0;
	long long first, second;
	for (int i = 0; i < n; i++) {
		int temp; cin >> temp;
		q.push(temp);
	}
	while (q.size() > 1) {
		first = q.top(); q.pop();
		second = q.top(); q.pop();
		long long w = first + second;
		res += w;
		q.push(w);
	}
	cout << res;
	return 0;
}*/
/*#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	priority_queue<int, vector<int>, greater<int>>right;
	priority_queue<int>left;
	int temp; cin >> temp;
	left.push(temp);
	cout << temp << "\n";
	for (int i = 2; i <= n; i++) {
		cin >> temp;
		if (i % 2 == 0) {
			int mid = left.top();
			if (temp >= mid)right.push(temp);
			else {
				left.pop();
				left.push(temp);
				right.push(mid);
			}
			continue;
		}
		int mid = left.top();
		if (temp <= mid) {
			left.push(temp);
			cout << mid << "\n";
		}
		else {
			right.push(temp);
			mid = right.top(); right.pop();
			left.push(mid);
			cout << mid << "\n";
		}
	}
	return 0;
}*/

//st数组

//P3865 【模板】ST 表 & RMQ 问题
/*#include <iostream>
#include<vector>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> m;
	const int LOG = 20;
	vector<int>arr(n + 1);
	vector<int>lg(n + 1);
	vector<vector<int>>st(n + 1, vector<int>(LOG));
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		st[i][0] = arr[i];
	}
	lg[1] = 0;
	for (int i = 2; i <= n; i++) lg[i] = lg[i / 2] + 1;

	for (int k = 1; k <= lg[n]; k++) {
		for (int i = 1; i + (1 << k) - 1 <= n; i++) {
			st[i][k] = max(st[i][k - 1], st[i + (1 << (k - 1))][k - 1]);
		}
	}
	while (m--) {
		int l, r; cin >> l >> r;
		int lg_len = lg[r - l + 1];
		cout << max(st[l][lg_len], st[r - (1 << lg_len) + 1][lg_len]) << "\n";
	}
	return 0;
}*/
//P2251 质量检测
/*#include<iostream>
#include<vector>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> m;
	const int LOG = 21;
	vector<vector<int>>st(n + 1, vector<int>(LOG));
	vector<int>lg(n + 1, 0);
	for (int i = 1; i <= n; i++) cin >> st[i][0];
	lg[1] = 0;
	for (int i = 2; i <= n; i++) lg[i] = lg[i / 2] + 1;
	for (int k = 1; k <= lg[n]; k++) {
		for (int i = 1; i + (1 << k) - 1 <= n; i++) {
			st[i][k] = min(st[i][k - 1], st[i + (1 << (k - 1))][k - 1]);
		}
	}
	int lg_len = lg[m];
	for (int i = 1; i + m - 1 <= n; i++) {
		cout << min(st[i][lg_len], st[i + m - (1 << lg_len)][lg_len]) << "\n";
	}
	return 0;
}*/
//P1198 [JSOI2008] 最大数
/*#include<iostream>
#include<vector>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int m, d; cin >> m >> d;
	const int LOG = 21;
	vector<vector<int>>st(m + 1, vector<int>(LOG));
	vector<int>lg(m + 1);
	lg[1] = 0;
	for (int i = 2; i <= m; i++) lg[i] = lg[i / 2] + 1;
	int t = 0, len_st = 0;

	while (m--) {
		char flag; cin >> flag;

		if (flag == 'A') {
			long long n; cin >> n;
			int neww = (n + t) % d;
			len_st++;
			st[len_st][0] = neww;
			for (int j = 1; j <= lg[len_st]; j++) {
				st[len_st][j] = max(st[len_st][j - 1],
					                st[len_st - (1 << (j - 1))][j - 1]);
			}
		}

		else {
			int L; cin >> L;
			t = max(st[len_st][lg[L]],
				    st[len_st - L + (1 << lg[L])][lg[L]]);
			cout << t << "\n";
		}
	}
	return 0;
}*/

//树状数组

//模板
/*#include<iostream>
#include<vector>
using namespace std;
struct BIT {
	vector<long long>tree;
	int len;

	BIT(int n) :len(n) { tree.assign(n + 1, 0); }
	int lowbit(int x) { return x & -x; }

	void init(vector<long long>& a) {
		for (int i = 1; i <= len; i++)
			add(i, a[i]);
	}

	void add(int x, long long delta) {
		for (int i = x; i <= len; i += lowbit(i))
			tree[i] += delta;
	}

	long long sum(int x) {
		long long res = 0;
		for (int i = x; i >= 1; i -= lowbit(i))
			res += tree[i];
		return res;
	}

	long long query(int l, int r) {
		return sum(r) - sum(l - 1);
	}
};*/
//P3374 【模板】树状数组 1
/*#include<iostream>
#include<vector>
using namespace std;
struct BIT {
	vector<long long>tree;
	int len;

	BIT(int n) :len(n) { tree.assign(n + 1, 0); }
	int lowbit(int n) {
		return n & (-n);
	}

	void init(vector<long long>& a) {
		for (int i = 1; i <= len; i++)
			add(i, a[i]);
	}

	void add(int x, long long delta) {
		for (int i = x; i <= len; i += lowbit(i))
			tree[i] += delta;
	}

	long long sum(int x) {
		int res = 0;
		for (int i = x; i > 0; i -= lowbit(i))
			res += tree[i];
		return res;
	}

	long long query(int l, int r) {
		return sum(r) - sum(l - 1);
	}
};
int main() {
	int n, m; cin >> n >> m;
	vector<long long>a(n + 1);
	BIT bit(n);

	for (int i = 1; i <= n; i++)cin >> a[i];
	bit.init(a);

	while (m--) {
		int flag; cin >> flag;
		if (flag == 1) {
			int x; long long k; cin >> x >> k;
			bit.add(x, k);
		}
		else {
			int x, y; cin >> x >> y;
			cout << bit.query(x, y) << "\n";
		}
	}
	
	return 0;
}*/
//P3368 【模板】树状数组 2
/*#include<iostream>
#include<vector>
using namespace std;
struct BIT {
	vector<long long>tree;
	int len;

	BIT(int n) :len(n) { tree.assign(n + 1, 0); }
	int lowbit(int n) {
		return n & (-n);
	}

	void init(vector<long long>& a) {
		for (int i = 1; i <= len; i++)
			add(i, a[i]);
	}

	void add(int x, long long delta) {
		if (x > len)return;
		for (int i = x; i <= len; i += lowbit(i))
			tree[i] += delta;
	}

	long long sum(int x) {
		int res = 0;
		for (int i = x; i > 0; i -= lowbit(i))
			res += tree[i];
		return res;
	}
};
int main() {
	int n, m; cin >> n >> m;
	vector<long long>a(n + 1);
	vector<long long>diff(n + 1);
	BIT bit(n);

	for (int i = 1; i <= n; i++)cin >> a[i];
	diff[1] = a[1];
	for (int i = 2; i <= n; i++) diff[i] = a[i] - a[i - 1];
	bit.init(diff);

	while (m--) {
		int flag; cin >> flag;
		if (flag == 1) {
			int x, y; long long k; cin >> x >> y >> k;
			bit.add(x, k);
			bit.add(y + 1, -k);
		}
		else {
			int x; cin >> x;
			cout << bit.sum(x) << "\n";
		}
	}

	return 0;
}*/
//P1908 逆序对
//还用到了离散化
/*#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct BIT {
	vector<int> tree;
	int len;

	BIT(int n) : len(n) { tree.assign(n + 1, 0); }
	int lowbit(int x) { return x & (-x); }

	void add(int x, int delta) {
		for (int i = x; i <= len; i += lowbit(i))
			tree[i] += delta;
	}

	int sum(int x) {
		int res = 0;
		for (int i = x; i > 0; i -= lowbit(i))
			res += tree[i];
		return res;
	}
};

int main() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	vector<int> b;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b.push_back(a[i]);
	}

	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());
	for (int i = 1; i <= n; i++) {
		int rk = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
		a[i] = rk;
	}

	BIT bit((int)b.size());
	long long res = 0;
	for (int i = 1; i <= n; i++) {
		res += (i - 1 - bit.sum(a[i]));
		bit.add(a[i], 1);
	}

	cout << res;
	return 0;
}*/
//P1966 [NOIP 2013 提高组] 火柴排队
/*#include<iostream>
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
}*/
//P3605 [USACO17JAN] Promotion Counting P
/*#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>>g;
vector<int>dfn, siz;
int timer = 0;
void dfs(int u) {
	dfn[u] = ++timer;
	siz[u] = 1;
	for (int son : g[u]) {
		dfs(son);
		siz[u] += siz[son];
	}
}

struct BIT {
	vector<int> tree;
	int len;

	BIT(int n) : len(n) { tree.assign(n + 1, 0); }
	int lowbit(int x) { return x & (-x); }

	void add(int x, int delta) {
		for (int i = x; i <= len; i += lowbit(i))
			tree[i] += delta;
	}

	int sum(int x) {
		int res = 0;
		for (int i = x; i > 0; i -= lowbit(i))
			res += tree[i];
		return res;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	vector<int>p(n + 1);
	for (int i = 1; i <= n; i++)cin >> p[i];

	g.resize(n + 1); dfn.resize(n + 1); siz.resize(n + 1);
	for (int i = 2; i <= n; i++) {
		int fa; cin >> fa;
		g[fa].push_back(i);
	}
	dfs(1);

	vector<int>ord(n);
	for (int i = 0; i < n; i++) ord[i] = i + 1;
	sort(ord.begin(), ord.end(), [&](int a, int b) {return p[a] > p[b]; });

	vector<int> ans(n + 1);
	BIT bit(n);

	for (int i = 0; i < n; i++) {
		int u = ord[i];
		ans[u] = bit.sum(dfn[u] + siz[u] - 1) - bit.sum(dfn[u] - 1);
		bit.add(dfn[u], 1);
	}
	for (int i = 1; i <= n; i++)cout << ans[i] << "\n";

	return 0;
}*/
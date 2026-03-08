//线性dp

//P1216 [IOI 1994 / USACO1.5] 数字三角形 Number Triangles
/*#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>>dp;
int main() {
	int r; cin >> r;
	vector<vector<int>>a(r, vector<int>(r, -1));
	for (int i = 0; i < r; i++)
		for (int j = 0; j <= i; j++) cin >> a[i][j];
	dp.assign(r, vector<int>(r, -1));
	dp[0][0] = a[0][0];
	for(int i=1;i<r;i++)
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				dp[i][j] = dp[i - 1][j] + a[i][j];
			}
			else if (j == i) {
				dp[i][j] = dp[i - 1][j - 1] + a[i][j];
			}
			else {
				dp[i][j] = a[i][j] + max(dp[i - 1][j], dp[i - 1][j - 1]);
			}
		}
	int max = 0;
	for (int i = 0; i < r; i++)max = (max > dp[r - 1][i] ? max : dp[r - 1][i]);
	cout << max;
	return 0;
}*/
//P1020 [NOIP 1999 提高组] 导弹拦截
/*#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int>a;
	int temp;
	while (cin >> temp) {
		a.push_back(temp);
		if (cin.peek() == '\n') {
			break;
		}
	}
	int n = a.size();
	vector<int>dp;
	for (int h : a) {
		auto it = upper_bound(dp.begin(), dp.end(), h, greater<int>());
		if (it == dp.end())dp.push_back(h);
		else *it = h;
	}
	cout << dp.size() << endl;
	vector<int>low;
	for (int h : a) {
		auto it = lower_bound(low.begin(),low.end(),h);
		if (it == low.end())low.push_back(h);
		else *it = h;
	}
	cout << low.size();
}*/
//P1091 [NOIP 2004 提高组] 合唱队形
/*#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	int n; cin >> n;
	vector<int>a(n, 0);
	for (int i = 0; i < n; i++)cin >> a[i];
	vector<int>left;
	vector<int>l(n, 0);
	for (int k = 0; k < n; k++) {
		auto it = lower_bound(left.begin(), left.end(), a[k]);
		l[k] = it - left.begin() + 1;
		if (it == left.end())left.push_back(a[k]);
		else *it = a[k];
	}
	vector<int>right;
	vector<int>r(n, 0);
	for (int k = n - 1; k >= 0; k--) {
		auto it = lower_bound(right.begin(), right.end(), a[k]);
		r[k] = it - right.begin() + 1;
		if (it == right.end())right.push_back(a[k]);
		else *it = a[k];
	}
	int best = 0;
	for (int i = 0; i < n; i++) best = max(l[i] + r[i] - 1, best);
	cout << n - best;
	return 0;
}*/
//P1095 [NOIP 2007 普及组] 守望者的逃离
/*#include<iostream>
#include<vector>
using namespace std;
int main() {
	int m, s, t; cin >> m >> s >> t;
	int curs = 0, dp = 0;
	for (int i = 1; i <= t; i++) {
		if (m >= 10) { m -= 10; curs += 60; }
		else m += 4;
		dp = max(dp + 17, curs);
		if (dp > s) { cout << "Yes\n" << i; return 0; }
	}
	cout << "No\n" << dp;
	return 0;
}*/
//P1541 [NOIP 2010 提高组] 乌龟棋
/*#include<iostream>
#include<vector>
using namespace std;
int main() {
	int n, m; cin >> n >> m;
	vector<int>score(n, 0);
	vector<int>card(4, 0);
	for (int i = 0; i < n; i++)cin >> score[i];
	for (int j = 0; j < m; j++) {
		int temp; cin >> temp;
		card[temp - 1]++;
	}
	vector<vector<vector<vector<int>>>>dp(card[0] + 1, vector<vector<vector<int>>>(card[1] + 1, vector<vector<int>>(card[2] + 1, vector<int>(card[3] + 1, score[0]))));
	for (int i = 0; i <= card[0]; i++) {
		for (int j = 0; j <= card[1]; j++) {
			for (int k = 0; k <= card[2]; k++) {
				for (int l = 0; l <= card[3]; l++) {
					int pos = i + 2*j + 3*k + 4*l;
					int best = score[0];
					if (i > 0) best = max(best, dp[i - 1][j][k][l] + score[pos]);
					if (j > 0) best = max(best, dp[i][j - 1][k][l] + score[pos]);
					if (k > 0) best = max(best, dp[i][j][k - 1][l] + score[pos]);
					if (l > 0) best = max(best, dp[i][j][k][l - 1] + score[pos]);
					dp[i][j][k][l] = best;
				}
			}
		}
	}
	cout << dp[card[0]][card[1]][card[2]][card[3]];
	return 0;
}*/
//P1868 饥饿的奶牛
/*#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int n; cin >> n;
	vector<pair<int, int>>a(n, { 0,0 });
	int s = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
		s = max(s, a[i].second);
	}
	vector<vector<int>>endy(s + 2);
	for (int i = 0; i < n; i++)endy[a[i].second + 1].push_back(a[i].first);
	vector<int>dp(s + 2, 0);
	dp[0] = 0;
	for (int i = 1; i < s + 2; i++) {
		int k = endy[i].size();
		int best = dp[i - 1];
		for (int j = 0; j < k; j++) {
			int x = endy[i][j], y = i - 1;
			best = max(best, dp[x] + y - x + 1);
		}
		dp[i] = best;
	}
	cout << dp[s + 1];
	return 0;
}*/
//P2679 [NOIP 2015 提高组] 子串
// 用到的知识点：滚动数组省内存，拆分状态
/*#include<iostream>
#include<vector>
#include<string>
using namespace std;
int const MOD = 1000000007;
int main() {
	int n, m, k; cin >> n >> m >> k;
	string a, b; cin >> a; cin >> b;
	vector<vector<int>> f_prev(k + 1, vector<int>(m + 1, 0)),
		                g_prev(k + 1, vector<int>(m + 1, 0)),
		                f_cur (k + 1, vector<int>(m + 1, 0)),
		                g_cur (k + 1, vector<int>(m + 1, 0));
	g_prev[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int p = 0; p <= k; p++) {
			fill(f_cur[p].begin(), f_cur[p].end(), 0);
			fill(g_cur[p].begin(), g_cur[p].end(), 0);
		}
		g_cur[0][0] = 1;
		for (int p = 1; p <= k; p++) {
			for (int j = 1; j <= m; j++) {
				g_cur[p][j] = (g_prev[p][j] + f_prev[p][j]) % MOD;
				if (a[i - 1] == b[j - 1]) {
					f_cur[p][j] = ((long long)f_prev[p][j - 1] + f_prev[p - 1][j - 1] + g_prev[p - 1][j - 1]) % MOD;
				}
			}
		}
		swap(f_prev, f_cur); swap(g_prev, g_cur);
	}
	cout << ((f_prev[k][m] + g_prev[k][m]) % MOD);
	return 0;
}*/

//背包dp

//P1048 [NOIP 2005 普及组] 采药
/*#include<iostream>
#include<vector>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t, m; cin >> t >> m;
	vector<int>dp(t + 1, 0);
	vector<pair<int, int>>a(m);
	for (int i = 0; i < m; i++) {
		int ti, val; cin >> ti >> val;
		a[i] = { ti,val };
	}
	for (int i = 0; i < m; i++) {
		for (int j = t; j > 0; j--) {
			auto [ti, val] = a[i];
			if (ti <= j)dp[j] = max(dp[j - ti] + val, dp[j]);
			else dp[j] = dp[j];
		}
	}
	cout << dp[t];
	return 0;
}*/
//P1855 榨取kkksc03
/*#include<iostream>
#include<vector>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, t; cin >> n >> m >> t;
	vector<pair<int, int>>a(n);
	for (int i = 0; i < n; i++) {
		int ti, p; cin >> ti >> p;
		a[i] = { ti,p };
	}
	vector<vector<int>> f_prev(t + 1, vector<int>(m + 1, 0)),
		g_prev(t + 1, vector<int>(m + 1, 0)),
		f_cur(t + 1, vector<int>(m + 1, 0)),
		g_cur(t + 1, vector<int>(m + 1, 0));
	g_prev[0][0] = 0;
	for (int i = 0; i < n; i++) {
		for (int p = 0; p <= t; p++) {
			fill(f_cur[p].begin(), f_cur[p].end(), 0);
			fill(g_cur[p].begin(), g_cur[p].end(), 0);
		}
		g_cur[0][0] = 0;
		auto [ti, pr] = a[i];
		for (int s = t; s > 0; s--) {
			for (int j = m; j > 0; j--) {
				g_cur[s][j] = max(f_prev[s][j], g_prev[s][j]);
				if (s >= ti && j >= pr) f_cur[s][j] = max(f_prev[s - ti][j - pr] + 1, g_prev[s - ti][j - pr] + 1);
				else f_cur[s][j] = 0;
			}
		}
		swap(f_prev, f_cur); swap(g_prev, g_cur);
	}
	cout << max(f_prev[t][m], g_prev[t][m]);
	return 0;
}*/
//P5020 [NOIP 2018 提高组] 货币系统
/*#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T; cin >> T;
	for (int o = 0; o < T; o++) {
		int n; cin >> n;
		vector<int>a(n);
		for (int i = 0; i < n; i++)cin >> a[i];
		sort(a.begin(), a.end());
		vector<int>currency;
		vector<bool>dp(a[n - 1] + 1, 0);
		currency.push_back(a[0]); dp[a[0]] = 1;
		for (int i = 1; i < n; i++) {
			int price = a[i];
			for (int j = a[i - 1] + 1; j <= price; j++) {
				for (int p : currency) {
					dp[j] = dp[j] || dp[j - p];
					if (dp[j])break;
				}
			}
			if (dp[price])continue;
			currency.push_back(price); dp[price] = 1;
		}
		cout << currency.size() << endl;
	}
	return 0;
}*/
//P1757 通天之分组背包
/*#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> m >> n;
	vector<vector<pair<int, int>>> grp(10001);
	int t = 0;
	for (int i = 0; i < n; i++) {
		int w, v, c;
		cin >> w >> v >> c;
		t = max(t, c);
		grp[c].push_back({ w,v });
	}
	vector<int> dp(m + 1, 0);
	for (int c = 1; c <= t; c++) {
		for (int j = m; j >= 0; j--) {
			for (auto [w, v] : grp[c]) {
				if (j >= w) dp[j] = max(dp[j], dp[j - w] + v);
			}
		}
	}
	cout << dp[m];
	return 0;
}*/
//P1064 [NOIP 2006 提高组] 金明的预算方案
/*#include<iostream>
#include<vector>
#include<tuple>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> m; n /= 10;
	vector<vector<pair<int, int>>>val(m);
	vector<tuple<int, int,int>>all(m);
	vector<int>index;
	for (int i = 0; i < m; i++) {
		int v, p, q; cin >> v >> p >> q;
		all[i] = { v / 10,v * p,q };
		if (q == 0) val[i].push_back({ v / 10,v * p }),
			        index .push_back(i);
	}
	for (int i = 0; i < m; i++) {
		auto [x, y, z] = all[i];
		if (z == 0)continue;
		val[z - 1].push_back({ x,y });
	}
	vector<int>dp_pre(n + 1, 0), dp_cur(n + 1, 0);
	int c = index.size();
	for (int i = 0; i < c; i++) {
		dp_cur = dp_pre;
		for (int j = n; j >= 0; j--) {
			auto [v, p] = val[index[i]][0];
			if (j < v)break;
			dp_cur[j] = max(dp_pre[j - v] + p, dp_pre[j]);
			int l = val[index[i]].size();
			if (l == 1)continue;
			auto [v1, p1] = val[index[i]][1];
			if (j >= v + v1)dp_cur[j] = max(dp_cur[j], dp_pre[j - v - v1] + p + p1);
			if (l == 2)continue;
			auto [v2, p2] = val[index[i]][2];
			if (j >= v + v2)dp_cur[j] = max(dp_cur[j], dp_pre[j - v - v2] + p + p2);
			if (j >= v + v1 + v2)dp_cur[j] = max(dp_cur[j], dp_pre[j - v - v1 - v2] + p + p1 + p2);
		}
		swap(dp_pre, dp_cur);
	}
	cout << dp_pre[n];
	return 0;
}*/

//区间dp

//P1880 [NOI1995] 石子合并
/*#include<iostream>
#include<vector>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	const long long INF = (1LL << 60);
	vector<vector<long long>>dpMax(2*n + 1, vector<long long>(2*n + 1, 0)),
		                     dpMin(2*n + 1, vector<long long>(2*n + 1, INF));
	vector<long long> a(2 * n + 1), pre(2 * n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i + n] = a[i];
	}
	for (int i = 1; i <= 2 * n; i++) pre[i] = pre[i - 1] + a[i];
	auto sum = [&](int l, int r) { return pre[r] - pre[l - 1]; };
	for (int i = 1; i <= 2*n; i++) { dpMax[i][i] = 0, dpMin[i][i] = 0; }
	for (int len = 2; len <= n; len++) {
		for (int l = 1; l + len - 1 <= 2*n; l++) {
			int r = l + len - 1;
			long long cost = sum(l, r);
			for (int k = l; k < r; k++) {
				dpMax[l][r] = max(dpMax[l][r], dpMax[l][k] + dpMax[k + 1][r] + cost);
				dpMin[l][r] = min(dpMin[l][r], dpMin[l][k] + dpMin[k + 1][r] + cost);
			}
		}
	}
	long long best = 0, worst = INF;
	for (int i = 1; i <= n; i++) {
		best = max(dpMax[i][i + n - 1], best);
		worst = min(dpMin[i][i + n - 1], worst);
	}
	cout << worst << "\n" << best << "\n";
	return 0;
}*/

//P3146 [USACO16OPEN] 248 G
/*#include<iostream>
#include<vector>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, best = 0; cin >> n;
	vector<vector<int>>dp(n + 1, vector<int>(n + 1, 0));
	vector<int> a(2 * n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) dp[i][i] = a[i], best = max(best, a[i]);
	for (int len = 2; len <= n; len++) {
		for (int l = 1; l + len - 1 <= n; l++) {
			int r = l + len - 1;
			for (int k = l; k < r; k++) {
				if (dp[l][k] != 0 && dp[l][k] == dp[k + 1][r]) {
					dp[l][r] = max(dp[l][k] + 1, dp[l][r]);
				}
			}
			best = max(best, dp[l][r]);
		}
	}
	cout << best;
	return 0;
}*/
//P1063 [NOIP 2006 提高组] 能量项链
/*#include<iostream>
#include<vector>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	vector<int>a(n);
	for (int i = 0; i < n; i++)cin >> a[i];
	vector<pair<int, int>>node(2 * n + 1);
	vector<vector<int>>dp(2 * n + 1, vector<int>(2 * n + 1,0));
	node[0] = { a[n - 1],a[0] };
	for (int i = 1; i <= 2 * n; i++) node[i] = { node[i - 1].second,a[i % n] };
	for (int i = 1; i <= 2 * n; i++) dp[i][i] = 0;
	for (int len = 2; len <= n; len++) {
		for (int l = 1; l + len - 1 <= 2 * n; l++) {
			int r = l + len - 1;
			for (int k = l; k < r; k++) {
				int cost = node[k].second * node[l].first * node[r].second;
				dp[l][r] = max(dp[l][r], dp[l][k] + dp[k + 1][r] + cost);
			}
		}
	}
	int best = 0;
	for (int i = 0; i < n; i++) best = max(dp[i + 1][i + n], best);
	cout << best;
	return 0;
}*/
//P1005 [NOIP 2007 提高组] 矩阵取数游戏
/*#include<iostream>
#include <string>
#include<vector>
using namespace std;

void print128(__int128 x) {
	if (x == 0) {
		cout << "0";
		return;
	}
	if (x < 0) {
		cout << "-";
		x = -x;
	}
	string s;
	while (x > 0) {
		s = char('0' + (x % 10)) + s;
		x /= 10;
	}
	cout << s;
}

__int128 read128() {
    string s;
    cin >> s;
    __int128 res = 0;
    bool flag = false;
    int start = 0;
    if (s[0] == '-') {
        flag = true;
        start = 1;
    }
    for (int i = start; i < s.size(); i++) res = res * 10 + (s[i] - '0');
    return flag ? -res : res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> m;
	vector<vector<__int128>>a(n, vector<__int128>(m));
	for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)a[i][j] = read128();
	__int128 ans = 0;
	for (int o = 0; o < n; o++) {
		vector<vector<__int128>>dp(m + 1, vector<__int128>(m + 1));
		for (int i = 1; i <= m; i++)dp[i][i] = a[o][i - 1] << m;
		for (int len = 2; len <= m; len++) {
			for (int l = 1; l + len - 1 <= m; l++) {
				int r = l + len - 1;
				__int128 head, tail;
				head = a[o][l - 1] << (m - len + 1);
				tail = a[o][r - 1] << (m - len + 1);
				dp[l][r] = max(dp[l + 1][r] + head, dp[l][r - 1] + tail);
			}
		}
		ans += dp[1][m];
	}
	print128(ans);
	return 0;
}*/
//P4170 [CQOI2007] 涂色
/*#include<iostream>
#include<string>
#include<string.h>
#include<vector>
using namespace std;
int main() {
	string s; cin >> s;
	int n = 0;
	for (; s[n] != '\0'; n++);
	vector<vector<int>>dp(n + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= n; i++)dp[i][i] = 1;
	for (int len = 2; len <= n; len++) {
		for (int l = 1; l + len - 1 <= n; l++) {
			int r = l + len - 1;
			dp[l][r] = dp[l][r - 1] + 1;
			for (int k = l; k < r; k++) {
				if (s[k - 1] == s[r - 1]) dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r - 1]);
			}
		}
	}
	cout << dp[1][n];
	return 0;
}*/
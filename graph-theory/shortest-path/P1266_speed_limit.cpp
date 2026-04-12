/*
Problem: P1266 Speed Limit
Source: https://www.luogu.com.cn/problem/P1266
Training List: https://www.luogu.com.cn/training/9391
Topic: Graph Theory
Subtopic: shortest-path
*/
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
typedef double D;
using namespace std;
struct RawEdge {
	int from, to;
	D len, speed; 
};
struct Edge {
	int to;
	D len;
	int speedId;
};
struct Node {
	D dist;
	int u;
	int sid;
	bool operator>(const Node& other) const {
		return dist > other.dist;
	}
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, target;
	cin >> n >> m >> target;
	vector<RawEdge> rawE;
	vector<D> speeds;
	speeds.push_back(70.0); 
	for (int i = 0; i < m; i++) {
		RawEdge temp;
		cin >> temp.from >> temp.to >> temp.len >> temp.speed;
		rawE.push_back(temp);
		if (temp.speed) speeds.push_back(temp.speed);
	}

	sort(speeds.begin(), speeds.end());
	speeds.erase(unique(speeds.begin(), speeds.end()), speeds.end());
	vector<vector<Edge>> g(n);
	for (RawEdge temp : rawE) {
		int id = -1;
		if (temp.speed != 0) {
			id = lower_bound(speeds.begin(), speeds.end(), temp.speed) - speeds.begin();
		}
		Edge e = { temp.to, temp.len, id };
		g[temp.from].push_back(e);
	}

	const D INF = 1e100;
	int S = speeds.size();
	vector<vector<D>> dist(n, vector<D>(S, INF));
	vector<vector<int>> vis(n, vector<int>(S, 0));
	vector<vector<int>> preU(n, vector<int>(S, -1));
	vector<vector<int>> preSid(n, vector<int>(S, -1));
	int initSid = lower_bound(speeds.begin(), speeds.end(), 70.0) - speeds.begin();
	priority_queue<Node, vector<Node>, greater<Node>> q;
	dist[0][initSid] = 0; q.push({ 0.0, 0, initSid });

	while (!q.empty()) {
		auto [di, u, sid] = q.top(); q.pop();
		if (vis[u][sid]) continue;
		vis[u][sid] = 1;

		for (Edge e : g[u]) {
			int v = e.to;
			int nextSid;
			D speedUsed;
			if (e.speedId == -1) {
				nextSid = sid;
				speedUsed = speeds[sid];
			}
			else {
				nextSid = e.speedId;
				speedUsed = speeds[nextSid];
			}
			D newDist = dist[u][sid] + e.len / speedUsed;
			if (dist[v][nextSid] > newDist) {
				dist[v][nextSid] = newDist;
				preU[v][nextSid] = u;
				preSid[v][nextSid] = sid;
				q.push({ newDist, v, nextSid });
			}
		}
	}

	D best = INF;
	int bestSid = -1;
	for (int sid = 0; sid < S; sid++) {
		if (dist[target][sid] < best) {
			best = dist[target][sid];
			bestSid = sid;
		}
	}
	if (bestSid == -1) {
		cout << "No path\n";
		return 0;
	}

	vector<int> path;
	int u = target, sid = bestSid;
	while (u != -1) {
		path.push_back(u);
		int pu = preU[u][sid];
		int psid = preSid[u][sid];
		u = pu;
		sid = psid;
	}
	reverse(path.begin(), path.end());

	for (int x : path) cout << x << " ";

	return 0;
}


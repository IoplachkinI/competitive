#include <bits/stdc++.h>


using namespace std;


int dfsroot, numcnt, rootchildren;
vector<vector<int>> adjlist;
vector<int> dfsnum, visited, dfslow, dfsparent;
vector<pair<int, int>> pigvalue;


void dfs(int v){
	dfsnum[v] = dfslow[v] = numcnt++;
	visited[v] = 1;

	for (const auto& u : adjlist[v]){
		if (!visited[u]){
			dfsparent[u] = v;
			if (v == dfsroot) rootchildren++;

			dfs(u);

			if (dfslow[u] >= dfsnum[v])
				pigvalue[v].second++;
			dfslow[v] = min(dfslow[v], dfslow[u]);
		}
		else if (u != dfsparent[v])
			dfslow[v] = min(dfslow[v], dfsnum[u]);
	}

	pigvalue[v].second += (v != dfsroot);
}


int main(){
	while (true){
		int n, m;
		cin >> n >> m;
		if (!n) break;
		adjlist.assign(n, vector<int>());
		dfsnum.assign(n, 0);
		dfslow.assign(n, 0);
		dfsparent.assign(n, 0);
		pigvalue.assign(n, {0, 0});
		for (int i = 0; i < n; i++)
			pigvalue[i].first = i;
		visited.assign(n, 0);
		numcnt = rootchildren = 0;

		while (true){
			int u, v;
			cin >> u >> v;
			if (u == -1) break;

			adjlist[u].push_back(v);
			adjlist[v].push_back(u);
		}

		dfsroot = 0;
		dfs(0);

		sort(pigvalue.begin(), pigvalue.end(), [](pair<int, int> i, pair<int, int> j){
				if (i.second != j.second) return i.second > j.second;
				return i.first < j.first;
				});

		for (int i = 0; i < m; i++){
			cout << pigvalue[i].first << ' ' << pigvalue[i].second << '\n';
		}
		cout << '\n';
	}
}

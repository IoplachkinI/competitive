#include <bits/stdc++.h>


using namespace std;


int numcnt, dfsroot, rootchildren;
vector<vector<int>> adjlist;
vector<vector<int>> edgematrix;
vector<int> visited, dfsnum, dfslow, dfsparent;


void dfs(int v){
	visited[v] = 1;
	dfsnum[v] = dfslow[v] = numcnt++;
	
	for (const auto& u : adjlist[v]){
		if (!visited[u]){
			dfsparent[u] = v;
			if (v == dfsroot) rootchildren++;

			dfs(u);

			if (dfslow[u] > dfsnum[v])
				edgematrix[min(u, v)][max(u, v)] = 1;
			dfslow[v] = min(dfslow[v], dfslow[u]);
		}
		else{
			if (dfsparent[v] == u) continue;
			dfslow[v] = min(dfslow[v], dfslow[u]);
		}
	}
}


int main(){
	while (true){
		int n;
		cin >> n;
		if (cin.eof()) break;
		numcnt = 0;
		adjlist.assign(n, vector<int>());
		edgematrix.assign(n, vector<int>(n));
		for (auto& a : edgematrix) for (auto& b : a) b = 0;
		visited.assign(n, 0);
		dfsnum.assign(n, 0);
		dfslow.assign(n, 0);
		dfsparent.assign(n, 0);
		
		for (int i = 0; i < n; i++){
			int v;
			cin >> v;
			char garbage;
			cin >> garbage;
			int nv;
			cin >> nv;
			cin >> garbage;
			for (int i = 0; i < nv; i++){
				int u;
				cin >> u;
				adjlist[v].push_back(u);
			}
		}

		for (int i = 0; i < n; i++){
			if (visited[i]) continue;
			dfsroot = i;
			dfs(i);
		}

		int ans = 0;
		for (auto& a : edgematrix) for (auto& b : a)
			ans += b;

		printf("%d critical links\n", ans);
		
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
			if (edgematrix[i][j]) printf("%d - %d\n", i, j);
		printf("\n");
	}
}

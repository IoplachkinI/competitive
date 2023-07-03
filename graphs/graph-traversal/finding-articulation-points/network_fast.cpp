#include <bits/stdc++.h>


using namespace std;


const int MAXN = 101;
vector<vector<int>> adjlist(MAXN, vector<int>());
vector<int> visited(MAXN);
vector<int> dfsnum(MAXN);
vector<int> dfslow(MAXN);
vector<int> dfsparent(MAXN);
vector<int> points(MAXN);
int numcnt, dfsroot, rootchildren;


void dfs(int v){
	dfslow[v] = dfsnum[v] = numcnt++;
	visited[v] = 1;

	for (const auto& a : adjlist[v]){
		if (!visited[a]) {
			dfsparent[a] = v;
			if (v == dfsroot) rootchildren++;
			dfs(a);
			if (dfslow[a] >= dfsnum[v]) 
				if (v != dfsroot || (v == dfsroot && rootchildren > 1))
					points[v] = 1;
			dfslow[v] = min(dfslow[v], dfslow[a]);
		}
		else{
			if (dfsparent[v] == a) continue;
			dfslow[v] = min(dfslow[v], dfsnum[a]);
		}
	}
}


int main(){
	while (true){
		for (auto& a : adjlist) a = {};
		for (int i = 0; i < MAXN; i++){
			visited[i] = dfsnum[i] = dfslow[i] = dfsparent[i] = points[i] = 0;
		}
		rootchildren = 0;
		numcnt = dfsroot = 1;

		int n, ans = 0;
		cin >> n;
		cin.ignore(100, '\n');
		if (!n) break;

		while (true){
			string s;
			getline(cin, s);
			istringstream iss (s);
			int v;
			iss >> v;
			if (!v) break;
			while (true){
				int u = 0;
				iss >> u;
				if (!u) break;
				adjlist[u].push_back(v);
				adjlist[v].push_back(u);
			}
		}
		
		dfs(1);
		for (int i = 1; i <= n; i++) ans += points[i];
		cout << ans << '\n';
	}
}

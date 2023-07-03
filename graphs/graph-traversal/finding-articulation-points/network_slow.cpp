#include <bits/stdc++.h>


using namespace std;


const int MAXN = 101;
int n;
vector<int> visited(MAXN);
vector<vector<int>> adjlist(MAXN, vector<int>());


void dfs(int v, int ignore){
	if (visited[v] || v == ignore) return;
	visited[v] = 1;
	for (const auto& a : adjlist[v])
		dfs(a, ignore);
}


int main(){
	while (true){
		cin >> n;
		cin.ignore(100, '\n');
		if (!n) break;
		for (auto& a : visited) a = 0;
		for (auto& a : adjlist) a = {};

		while (true){
			int v = 0;
			string str;
			getline(cin, str);
			istringstream iss(str);
			iss >> v;
			if (!v) break;
			while(true){
				int a = 0;
				iss >> a;
				if (!a) break;
				adjlist[v].push_back(a);
				adjlist[a].push_back(v);
			}
		}
		
		int ans = 0;
		for (int ignore = 1; ignore <=n; ignore++){
			int cnt = 0;
			for (auto& a : visited) a = 0;
			for (int i = 1; i <= n; i++){
				if (visited[i] || i == ignore) continue;	
				cnt++;
				dfs(i, ignore);
			}
			if (cnt > 1)
				ans++;
		}

		cout << ans << '\n';
	}

}

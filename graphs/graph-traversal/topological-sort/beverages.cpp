#include <bits/stdc++.h>

using namespace std;


const int MAXN = 101;
int n;
vector<vector<int>> adjlist (MAXN);
vector<int> sorted (MAXN);
vector<int> visited (MAXN);


void dfs(int cur){
    if (visited[cur]) return;
    visited[cur] = 1;
    for (int i = 0; i < adjlist[cur].size(); i++)
        dfs(adjlist[cur][i]);
    sorted.push_back(cur);
}


//DOESN'T WORK because at each choice of a vertex dfs doesnt consider valid vertices that aren't 
//connected to the previous one, and this matters here, as it is required to choose the vertex that
//came first in the input
int main(){
    int _case = 0;
    while (true){
        _case++;
        cin >> n;
        if (cin.eof()) break;

        map<string, int> strToInd;
        map<int, string> indToStr;
        for (auto& a : adjlist) a = {};
        for (auto& a : visited) a = 0;
        sorted.clear();

        for (int i = 0; i < n; i++){
            string in;
            cin >> in;
            strToInd[in] = i; 
            indToStr[i] = in;
        }

        int m;
        cin >> m;
        for (int i = 0; i < m; i++){
            string a, b;
            cin >> a >> b;
            int _a = strToInd[a], _b = strToInd[b];
            adjlist[_a].push_back(_b);
        }

        for (int i = 0; i < n; i++)
            sort(adjlist[i].begin(), adjlist[i].end());

        for (int i = 0; i < n; i++)
            if (!visited[i]) dfs(i);

        cout << "Case #" << _case << ": Dilbert should drink beverages in this order:";
        for (auto it = sorted.rbegin(); it < sorted.rend(); it++)
            cout << ' ' << indToStr[*it];
        cout << ".\n";

    }
}
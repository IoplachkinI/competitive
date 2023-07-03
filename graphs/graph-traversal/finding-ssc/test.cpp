#include <bits/stdc++.h>


using namespace std;


int numcnt;
map<string, int> charToInd;
map<int, string> indToChar;
vector<vector<int>> adjlist;
vector<int> dfsnum, dfslow, visited, currentssc, S;
vector<vector<string>> ans;


void dfs(int u){
    dfsnum[u] = dfslow[u] = numcnt++;
    visited[u] = currentssc[u] = 1;
    S.push_back(u);

    for (const auto& v : adjlist[u]){
        if (!visited[v])
            dfs(v);
        if (currentssc[v])
            dfslow[u] = min(dfslow[u], dfslow[v]);
    }

    if (dfsnum[u] == dfslow[u]){
        vector<int> s;
        while (true){
            int v = S.back();
            S.pop_back();
            s.push_back(v);
            currentssc[v] = 0;
            if (v == u) break;
        }
        ans.push_back({});
        for (const auto& a : s)
            ans[ans.size()-1].push_back(indToChar[a]);
    }
}


int main(){
    int first = 1;
    while (true){
        int n;
        cin >> n;
        if (!n) break;

        if (!first) cout << '\n';
        first = 0;

        int ind = 0;
        numcnt = 0;
        adjlist.clear();
        charToInd.clear();
        indToChar.clear();
        for (int i = 0; i < n; i++){
            vector<string> in (5);
            string v;
            int newchars = 0;
            for (int j = 0; j < 5; j++){
                cin >> in[j];
                if (!charToInd.count(in[j])){
                    charToInd[in[j]] = ind;
                    indToChar[ind] = in[j];
                    ind++;
                    newchars++;
                }
            }
            for (int j = 0; j < newchars; j++) adjlist.push_back({});
            cin >> v;
            for (int j = 0; j < 5; j++){
                if (v == in[j]) continue;
                adjlist[charToInd[v]].push_back(charToInd[in[j]]);
            }
        }

        dfsnum.assign(ind, 0);
        dfslow = visited = currentssc = dfsnum;
        S.clear();
        ans.clear();
        int cnt = 0;
        /*
        for (const auto& a : adjlist){
            cout << indToChar[cnt] << ": ";
            for (const auto& b : a) cout << indToChar[b] << ' ';
            cout << '\n';
            cnt++;
        }
        */

        for (int i = 0; i < ind; i++)
            if (!visited[i]) dfs(i);

        for (auto& a : ans) sort(a.begin(), a.end());
        sort(ans.begin(), ans.end());

        for (const auto& a : ans){
            int first = 1;
            for (const auto& b : a){
                if (!first) cout << ' ';
                cout << b;
                first = 0;
            }
            cout << '\n';
        }
    }
}

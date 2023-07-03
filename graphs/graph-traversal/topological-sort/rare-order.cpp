#include <bits/stdc++.h>


using namespace std;

const int MAXN = 30;
vector<vector<int>> adjlist (MAXN);
vector<int> visited (MAXN);
vector<int> present (MAXN);
vector<int> sorted;
vector<string> strs;


void dfs(int cur){
    if (visited[cur]) return;
    visited[cur] = 1;
    for (int i = 0; i < adjlist[cur].size(); i++)
        dfs(adjlist[cur][i]);
    sorted.push_back(cur);
}


int main(){
    int maxlen = 0;
    for (int i = 0; i < MAXN; i++) visited[i] = present[i] = 0;
    while (true){ 
        string str;
        getline(cin, str);
        if (str == "#") break;
        for (const auto& c : str) present[c-'A'] = 1;
        maxlen = max(maxlen, (int)str.size());
        strs.push_back(str);
    }

    for (int i = 1; i < strs.size(); i++){
        for (int j = 0; j < min(strs[i-1].size(), strs[i].size()); j++){
            if (strs[i-1][j] != strs[i][j]) {
                adjlist[strs[i-1][j]-'A'].push_back(strs[i][j]-'A');
                break;
            }
        }
    }

    vector<int> parentless = present;
    for (const auto& a : adjlist)
        for (const auto& b : a)
            parentless[b] = 0;

    vector<vector<int>>& a = adjlist;
    int root = -1;
    for (int i = 0; i < MAXN && root == -1; i++){
        if (parentless[i]) root = i;
    }

    dfs(root);
    for (auto it = sorted.rbegin(); it < sorted.rend(); it++)
        printf("%c", *it+'A');
    printf("\n");
        
}
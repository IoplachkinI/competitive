#include <bits/stdc++.h>

using namespace std;

int n, cnt;
vector<vector<int>> adjmatrix;
vector<int> visited;
string ans;
map<char, int> charToInd;
map<int, char> indToChar;

void dfs(){
    bool done = true;
    for (int i = 0; i < n && done; i++)
        done = visited[i];
    if (done){
        cnt++;
        cout << ans << '\n';
        return;
    }
    
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        bool good = true;
        for (int j = 0; j < n && good; j++) 
            good = !(adjmatrix[j][i] && !visited[j]);
        if (!good) continue;
        visited[i] = 1;
        if (ans.size()) ans.push_back(' ');
        ans.push_back(indToChar[i]);
        dfs();
        visited[i] = 0;
        ans.pop_back();
        if (ans.size()) ans.pop_back();
    }

}

int main(){
    int t;
    cin >> t;
    cin.ignore(100, '\n');
    while (t--){
        cin.ignore(100, '\n');
        string in;
        priority_queue<char, vector<char>, greater<char>> pq;
        charToInd.clear();
        indToChar.clear();

        getline(cin, in);

        for (int i = 0; i < in.size(); i+=2)
            pq.push(in[i]);
        
        n = pq.size();
        adjmatrix.assign(n, {});
        visited.assign(n, 0);
        for (auto&a : adjmatrix) a.assign(n, 0);
        int ind = 0;
        while (!pq.empty()){
            charToInd[pq.top()] = ind;
            indToChar[ind] = pq.top();
            ind++;
            pq.pop();
        }

        getline(cin, in);
        for (int i = 2; i < in.size(); i+=4){
            int a = charToInd[in[i-2]];
            int b = charToInd[in[i]];
            adjmatrix[a][b] = 1;
        }

        auto& a = adjmatrix;

        ans = "";
        cnt = 0;

        dfs();
        if (!cnt) cout << "NO\n";
        if (t) cout << '\n';
    }
}
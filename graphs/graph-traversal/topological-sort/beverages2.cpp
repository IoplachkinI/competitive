#include <bits/stdc++.h>


using namespace std;




int main(){
    const int MAXN = 101;
    int n;
    vector<vector<int>> adjmatrix(MAXN, vector<int>(MAXN));
    vector<int> sorted;
    vector<int> visited(MAXN);
    int _case = 0;
    while (true){
        _case++;
        cin >> n;
        if (cin.eof()) break;

        map<string, int> strToInd;
        map<int, string> indToStr;
        sorted.clear();
        for (int i = 0; i < n; i++) {
            visited[i] = 0;
            for (int j = 0; j < n; j++)
                adjmatrix[i][j] = 0;
        }

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
            adjmatrix[strToInd[a]][strToInd[b]] = 1;
        }

        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++) {
            int degree = 0;
            for (int j = 0; j < n; j++)
                degree += adjmatrix[j][i];
            if (degree == 0) {
                pq.push(i);
                visited[i] = 1;
            }
        }

        while (!pq.empty()){
            int cur = pq.top();
            sorted.push_back(cur);
            pq.pop();
            for (int i = 0; i < n; i++) adjmatrix[cur][i] = 0;
            for (int i = 0; i < n; i++) {
                int degree = 0;
                for (int j = 0; j < n; j++)
                    degree += adjmatrix[j][i];
                if (degree == 0 && !visited[i]) {
                    pq.push(i);
                    visited[i] = 1;
                }
            }
        }

        cout << "Case #" << _case << ": Dilbert should drink beverages in this order:";
        for (const auto& a : sorted)
            cout << " " << indToStr[a];
        cout << ".\n\n";

    }
}
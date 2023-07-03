#include <bits/stdc++.h>

using namespace std;

#define o cout

int main(){
    int t;
    cin >> t;
    //ofstream o;
    //o.open("out.txt");
    while (t--){
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> edges (m);
        for (int i = 0; i < m; i++) edges[i] = {-1, -1};
        bool graph = true;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                int a; cin >> a;
                if (a && graph){
                    if (edges[j].second > -1) graph = false;
                    else if (edges[j].first > -1) {
                        edges[j].second = i;
                        if (count(edges.begin(), edges.end(), edges[j]) > 1) graph = false;
                    }
                    else edges[j].first = i;
                } 
            }
        }

        for (int i = 0; i < m && graph; i++) if (edges[i].second < 0) graph = false;

        if (graph) o << "Yes\n";
        else o << "No\n";
    }
    //o.close();
}
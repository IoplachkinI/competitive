#include <bits/stdc++.h>

using namespace std;

int main(){
    int t, _case=0;
    cin >> t;
    while (t--){
        _case++;
        int n;
        cin >> n;
        vector<int> edges(n+1);
        vector<int> len;
        len.assign(n+1, 0);
        set<int> path;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            cin >> edges[a];
        }

        int maxlen = 0, maxind = 0;
        for (int start = 1; start <= n; start++){
            path.clear();
            if (len[start]) continue;
            int cur = start;
            while (!len[cur]){
                path.insert(cur);
                for (auto& a : path) len[a]++;
                cur = edges[cur];
            }

            if (path.count(cur)){
                int _cur = edges[cur];
                while (_cur != cur){
                    len[_cur] = len[cur];
                    _cur = edges[_cur];
                }
            }
            else {
                for (auto& a : path) len[a] += len[cur];
            }
            if (len[start] > maxlen){
                maxlen = len[start];
                maxind = start;
            }
        }

        printf("Case %d: %d\n", _case, maxind);
    }
}
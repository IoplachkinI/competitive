#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int m;
        cin >> m;
        vector<pair<int, int>> v;
        while (true){
            int l, r;
            cin >> l >> r;
            if (!l && !r) break;
            v.push_back({l, r});
        }

        sort(v.begin(), v.end(), [](pair<int, int> i, pair<int, int> j){
            if(i.first != j.first) return i.first < j.first;
            else return i.second > j.second;
        });

        int start = 0, lastgood = -1, count = 0;
        vector<int> chosen;
        chosen.assign(v.size(), 0);
        for (int i = 0; i <= v.size() && start < m; i++){
            if (i == v.size() || v[i].first > start){
                if(lastgood < 0) break;

                if (start < m) {
                    chosen[lastgood] = 1;
                    count++;
                    if (start == v[lastgood].second) break;
                    start = v[lastgood].second;
                    if (i == v.size()) break;
                    i--;
                }
            }

            else if (v[i].second > v[lastgood].second) lastgood = i;
        }
        if (start < m) cout << "0\n";
        else {
            cout << count << '\n';
            for (int i = 0; i < v.size(); i++){
                if (chosen[i]) cout << v[i].first << ' ' << v[i].second << '\n';
            }
        }
        if (t)cout << '\n';
    }
}
#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<vector<int>> v;
    int cnt = 0;
    while (true){
        cnt++;
        int w, iq;
        cin >> w >> iq;
        if (cin.eof()) break;
        v.push_back({w, iq, cnt});
    }

    sort(v.begin(), v.end(), [](vector<int> i, vector<int> j){
        if (i[1] == j[1]) return i[0] < j[0];
        return i[1] > j[1];
    });

    vector<vector<int>> lis (v.size(), vector<int>(2));

    for (int i = 0; i < v.size(); i++){
        lis[i] = {1, i};
        for (int j = i - 1; j >= 0; j--){
            if (v[i][0] > v[j][0] && lis[j][0] + 1 > lis[i][0]) {
                lis[i][0] = lis[j][0] + 1;
                lis[i][1] = j;
            }
        }       
    }

    int maxind = 0;
    for (int i = 0; i < lis.size(); i++){
        if (lis[i][0] > lis[maxind][0]) maxind = i;
    }
    int curind = maxind;
    vector<int> res(lis[maxind][0]);
    cout << lis[maxind][0] << '\n';
    for (int i = 0; i < lis[maxind][0]; i++){
        res[i] = v[curind][2];
        curind = lis[curind][1];
    }

    for (auto it = res.rbegin(); it < res.rend(); it++)
        cout << *it << '\n';

}
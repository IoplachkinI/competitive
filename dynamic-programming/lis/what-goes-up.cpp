#include <bits/stdc++.h>

using namespace std;

//n^2, slower, lis(i) = max length of a sequence that ends with v[i]

int main(){
    vector<int> v;
    vector<vector<int>> lis;
    int cnt = 0;
    while (true){
        int n;
        cin >> n;
        if (cin.eof()) break;
        v.push_back(n);
        lis.push_back({1, cnt});
        cnt++;
    }
    
    for (int i = 0; i < v.size(); i++){
        for (int j = i - 1; j >= 0; j--){
            if (lis[j][0] + 1 > lis[i][0] && v[i] > v[j]){
                lis[i][0] = lis[j][0] + 1;
                lis[i][1] = j;
            }
        }
    }

    int maxind = 0;
    for (int i = 0; i < v.size(); i++)
        if (lis[i][0] >= lis[maxind][0])
            maxind = i;
    
    cout << lis[maxind][0] << '\n';
    cout << "-\n";

    int curind = maxind;
    vector<int> res (lis[maxind][0]);
    for (int i = 0; i < lis[maxind][0]; i++){
        res[i] = v[curind];
        curind = lis[curind][1];
    }

    for (auto it = res.rbegin(); it < res.rend(); it++){
        cout << *it << "\n";
    }

}
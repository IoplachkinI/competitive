#include <bits/stdc++.h>

using namespace std;

//l[i] = least element that ends a sequence of length i; l != lis

int main(){
    vector<int> v;
    vector<pair<int, int>> l;
    int cnt = 0;
    while (true){
        int n;
        cin >> n;
        if (cin.eof()) break;
        v.push_back(n);
        cnt++;
    }

    l.assign(v.size(), {INT32_MAX, 0});

    vector<int> memo(v.size()); //memo[i] = prev element to i in lis
    for (int i = 0; i < v.size(); i++){
        auto it = upper_bound(l.begin(), l.end(), pair<int, int>{v[i], 0});
        *it = {v[i], i};
        if (it != l.begin())
            memo[i] = (*(it-1)).second;
    }

    auto last = lower_bound(l.begin(), l.end(), pair<int, int>{INT32_MAX, 0});
    int maxlen = distance(l.begin(), last);

    int curind = l[maxlen-1].second;
    cout << maxlen << "\n-\n";
    vector<int> res(maxlen);
    for (int i = 0; i < maxlen; i++){
        res[i] = curind;
        curind = memo[curind];
    }

    for (auto it = res.rbegin(); it < res.rend(); it++){
        cout << v[*it] << "\n";
    }

}
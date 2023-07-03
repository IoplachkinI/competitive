#include <bits/stdc++.h>

using namespace std;

int main(){
    string str;
    cin >> str;

    vector<vector<int>> v (100);
    for (int i = 0; i < str.size(); i++){
        v[str[i]-'A'].push_back(i);
    }

    int q;
    cin >> q;

    while (q--){
        string s;
        cin >> s;
        int pos = -1;
        bool good = true;
        int first = -1, last = -1;
        for (int i = 0; i < s.size() && good; i++){
            const auto it = upper_bound(v[s[i] - 'A'].begin(), v[s[i] - 'A'].end(), pos);
            if (it == v[s[i] - 'A'].end()) good = false;
            else pos = *it;
            if (first < 0) first = pos;
        }
        last = pos;
        
        if (!good) cout << "Not matched\n";
        else cout << "Matched " << first << ' ' << last << '\n';
    }

}
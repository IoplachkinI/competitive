#include <bits/stdc++.h>

using namespace std;

int main(){
    bool first = true;
    while (true){
        if (first) first = false;
        else printf("\n");
        int n;
        cin >> n;
        if (!n) break;

        vector<int> v(n);
        set<int> s;
        multiset<int> ms;
        int maxocc = 0, distinct;
        for (int i = 0; i < n; i++){
            int in;
            cin >> in;
            v[i] = in;
            s.insert(in);
            ms.insert(in);
            int curcount = ms.count(in);
            if (curcount > maxocc) maxocc = curcount;
        }

        distinct = s.size();
        for (const auto& el : s){
            int toinsert = maxocc - ms.count(el);
            for (int i = 0; i < toinsert; i++)
                v.push_back(0);
        }

        sort(v.begin(), v.end());
        cout << maxocc << '\n';
        for(int i = 0; i < maxocc; i++){
            for(int j = 0; j < distinct; j++){
                int val = v[j * maxocc + i];
                if (val) cout << val;
                if (j < distinct - 1 && val) cout << " ";
            }
            cout << '\n';
        }
        

    }
}
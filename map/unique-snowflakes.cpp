#include <bits/stdc++.h>

using namespace std;

#define o cout

int main(){
    //ofstream o;
    //o.open("out.txt");
    long long t;
    cin >> t;
    while (t--){
        unordered_map<int, int> m;
        int n;
        cin >> n;
        vector<int> startEnd (n), endStart(n + 1); //индекс элемента - начало отрезка, значение - конец (вместо пар)
        endStart[n] = -1;
        for (int i = 0; i < n; i++) {
            int s;
            cin >> s;
            startEnd[i] = n;
            endStart[i] = -1;
            if (m.count(s)){
                startEnd[m[s]] = i;
                endStart[i] = m[s];
            }
            m[s] = i;
        }
       
        int max = 0;
        
        if (startEnd.empty()) {
            o << n << '\n';
            continue;
        }
        
        int curEnd = 0;

        for (int p = 0; p < n; p++){
            int len = 0;
            pair<int, int> range = {p, startEnd[p]};
            pair<int, int> subrange = {endStart[curEnd], curEnd};
            len = range.second - range.first;

            endStart[range.second] = -1;

            for (;curEnd < n && subrange.first == -1; curEnd++) {
                if (endStart[curEnd] != -1) subrange = {endStart[curEnd], curEnd};
            }
            curEnd--;

            /*endStart.erase(lower_bound(endStart.begin(), endStart.end(), 
                pair<int, int>{range.second, range.first}));
            pair<int, int> subrange = *endStart.begin();


            int psub = 0;
            while (endStart[psub].first < range.second && psub < endStart.size()){
                if (endStart[psub].second > range.first) {
                    len = endStart[psub].first - range.first;
                    break;
                }
                psub++;
            }*/

            //endStart.erase(endStart.begin(), lower_bound(endStart.begin(), endStart.end(), pair<int, int>{range.first, 0}));

            if (subrange.first > range.first && subrange.second < range.second) 
                len = subrange.second - range.first;

            max = (len > max) ? len : max;
        }

        o << max << '\n';
    }
    //o.close();
}
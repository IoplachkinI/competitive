#include <bits/stdc++.h>

using namespace std;

int main(){
    int n = 0;
    while (true){
        if (!n) {
            cin >> n;
            cin.ignore(100, '\n');
        }
        if (cin.eof()) break;
        string in;
        map<int, int> m;
        vector<vector<int>> v;
        getline(cin, in);

        int start = 0, end = 0, cnt = 0;
        while (true){
            end = in.find(' ', start + 1);
            if (end == string::npos) {
                m[cnt] = stoi(in.substr(start, in.size() - start)) - 1;
                break;
            };
            m[cnt] = stoi(in.substr(start, in.size() - start)) - 1;
            cnt++;
            start = end + 1;
        }

        /*for (const auto& el : m){
            cout << el.first << "=" << el.second << "\n";
        }*/

        int curv = 0;
        while (true){
            getline(cin, in);
            if (in.size() == 0 || cin.eof()) break;
            if (in.find(' ') == string::npos) {
                n = stoi(in);
                break;
            }
            v.push_back(vector<int> (n));
            start = 0, cnt = 0; //end = 0
            while (true){
                end = in.find(' ', start + 1);
                if (end == string::npos) {
                    v[curv][stoi(in.substr(start, in.size() - start)) - 1] = m[cnt];
                    break;
                }
                v[curv][stoi(in.substr(start, in.size() - start)) - 1] = m[cnt];
                cnt++;
                start = end + 1;
            }
            curv++;
        }

        for (const auto& a : v){
            vector<int> minend;
            minend.assign(a.size(), INT32_MAX);
            for (int i = 0; i < a.size(); i++){
                auto it = upper_bound(minend.begin(), minend.end(), a[i]);
                *it = a[i];
            }
            /*for (const auto& el : minend){
                cout << el << ' ';
            }
            cout << '\n';*/
            int ans = distance(minend.begin(), lower_bound(minend.begin(), minend.end(), INT32_MAX));
            cout << ans << '\n';
        }

        /*for (const auto& a : v){
            for (const auto& b : a){
                cout << b << ' ';
            }
            cout << '\n';
        }*/

    }
}
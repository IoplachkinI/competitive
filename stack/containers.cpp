#include <bits/stdc++.h>

using namespace std;

//#define o cout
//#define i cin

int main(){
    ofstream o;
    ifstream i;
    o.open("out.txt");
    i.open("in.txt");
    string str;
    i >> str;
    int cnt = 0;
    while (str.compare("end")){
        cnt++;
        int total = 0, res = 0;
        vector<stack<int>> v;
        set <int> chars;
        //cout << '\n';
        for (const auto& c : str){
            //cout << c - 'A' << ' ';
            chars.insert(c);
            total++;
        }
        //cout << '\n';

        while (total){
            int end = v.size() - 1;
            int container = str[str.length() - total] - 'A';
            bool found = false;

            for (int i = 0; i <= end; i++){
                if (v[i].top() >= container) {
                    found = true;
                    v[i].push(container);

                }
            }

            if (!found) {
                v.push_back({});
                v[end + 1].push(container);
            }

            total--;
        }
        res = (chars.size() < v.size()) ? chars.size() : v.size();

        o << "Case " << cnt << ": " << res << '\n';
        for (auto& a : v){
            while (!a.empty()) {
                cout << a.top() << ' ';
                a.pop();
            }
            cout << '\n';
        }
        cout << '\n';

        i >> str;

    }
    o.close();
    i.close();
}
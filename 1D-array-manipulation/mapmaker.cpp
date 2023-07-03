#include <bits/stdc++.h>


using namespace std;


int main(){
    int n, r;
    cin >> n >> r;

    map<string, vector<int>> m;

    while (n--){
        string name;
        cin >> name;
        m[name] = vector<int>();

        int base, byte, D;
        cin >> base >> byte >> D;
        m[name].push_back(base);
        m[name].push_back(byte);
        m[name].push_back(D);
        m[name].resize(3 + 2 * D);

        for (int i = 0; i < 2 * D; i++){
            cin >> m[name][3 + i];
        }

    }

    while (r--){
        string name;
        cin >> name;

        vector <int> ref (m[name][2]);

        for (int i = 0; i < m[name][2]; i++){
            cin >> ref[i];
        }

        int adress;
        vector<int> c (m[name][2] + 1);
        c[m[name][2]] = m[name][1];
        c[0] = m[name][0] - c[m[name][2]] * m[name][3 + (m[name][2] - 1) * 2];

        for (int i = m[name][2] - 1; i > 0; i--){
            c[i] = c[i+1] * (m[name][3 + i * 2 + 1] - m[name][3 + i * 2] + 1);
            c[0] -= c[i] * m[name][3 + (i - 1) * 2];
        }

        adress = c[0];
        for (int i = 1; i < c.size(); i++){
            adress += c[i] * ref[i - 1];
        }

        cout << name + '[' + to_string(ref[0]);
        for (int i = 1; i < ref.size(); i++){
            cout << ", " + to_string(ref[i]);
        }
        cout << "] = " << to_string(adress) + '\n';
    }
}
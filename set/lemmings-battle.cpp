#include <bits/stdc++.h>

using namespace std;

#define o cout

int main(){
    //ofstream o;
    //o.open("out.txt");
    int n;
    cin >> n;
    while (n--){
        int k, sg, sb;
        multiset<int, greater<int>> g, b;
        cin >> k >> sg >> sb;

        for (int i = 0; i < sg; i++) {
            int p; cin >> p; g.insert(p);

        }
        for (int i = 0; i < sb; i++){
            int p; cin >> p; b.insert(p);
        }

        while (!g.empty() && !b.empty()){
            auto itg = g.begin(), itb = b.begin();
            vector<multiset<int, greater<int>>::iterator> vb (k), vg(k);

            for (int i = 0; i < k; i++){
                if (itg == g.end() || itb == b.end()) {
                    vg.resize(i);
                    vb.resize(i);
                    break;
                }
                vb[i] = itb;
                vg[i] = itg;
                itg++; itb++;
            }

            for (int i = 0; i < vb.size(); i++){
                b.erase(vb[i]);
                g.erase(vg[i]);
                if (*vg[i] > *vb[i]) g.insert(*vg[i] - *vb[i]);
                else if (*vb[i] > *vg[i]) b.insert(*vb[i] - *vg[i]);
            }
        }

            if (g.empty() && b.empty()) o << "green and blue died\n";
            else if (g.empty()) {
                o << "blue wins\n";
                for (const auto& el : b) o << el << '\n';
            }
            else {
                o << "green wins\n";
                for (const auto& el : g) o << el << '\n';
            }
        if (n) o << '\n';
    }
    //o.close();
}
#include <bits/stdc++.h>


using namespace std;

#define o cout

int main(){
    //ofstream o;
    //o.open("out.txt");
    int n, m;
    cin >> n >> m;

    while (n != 0 || m != 0){
        bitset<1000001> b;
        bool conflict = false;
        for (int i = 0; i < n; i++){
            bool touching = false;
            int s, e;
            cin >> s >> e;
            for (int j = s; j <= e && !conflict; j++){
                if (b.test(j) && touching) conflict = true;
                else if (b.test(j)) touching = true;
                else b.set(j);
            }
        }
        for (int i = 0; i < m; i++){
            int s, e, r;
            cin >> s >> e >> r;
            for (;s <= 1000000 && !conflict; s = s + r, e = (e + r > 1000000) ? 1000000 : e + r){
                bool touching = false;
                for (int j = s; j <= e && !conflict; j++){
                    if (b.test(j) && touching) conflict = true;
                    else if (b.test(j)) touching = true;
                    else b.set(j);
                }
            }
        }

        if (conflict) o << "CONFLICT\n";
        else o << "NO CONFLICT\n";

        cin >> n >> m;
    }

    //o.close();
}
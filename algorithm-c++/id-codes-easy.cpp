#include <bits/stdc++.h>


using namespace std;


int main(){
    string in;
    cin >> in;

    while (in.compare("#") != 0){
        bool last = !next_permutation(in.begin(), in.end());
        if (last) cout << "No Successor\n";
        else cout << in << '\n';
        cin >> in;
    }
}
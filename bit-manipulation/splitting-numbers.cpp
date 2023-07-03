#include <bits/stdc++.h>


using namespace std;

#define o cout

int main(){
    int n;
    cin >> n;
    while (n != 0){
        vector<int> ind;
        int a = 0, b = 0;
        //string bin;
        for (int i = 0; i < 32; i++){
            if (n & (1 << i)) ind.push_back(i);
            //bin += to_string((n & (1 << i)) != 0);
        }

        /*for (const auto& el : ind){
            o << el << ' ';
        }*/
        //reverse(bin.begin(), bin.end());
        //o << '\n' << bin << '\n';

        for (int i = 0; i < ind.size(); i++){
            if (i % 2) b |= (1 << ind[i]);
            else a |= (1 << ind[i]);
        }    

        o << a << ' ' << b << '\n';       
        cin >> n;
    }
}
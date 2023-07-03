#include <bits/stdc++.h>

using namespace std;


//UNFINISHED - too many parameters and it's very annoying, might come back later...
int n, x, t, k;
const int MAXK = 101, MAXREM = 10001, MAXN = 11, MAXF = 11;

vector<vector<vector<int>>> memo(MAXK, vector<vector<int>>(MAXREM, vector<int>(2 * (MAXN + 1))));
vector<int> p(MAXK);
vector<vector<int>> f(MAXN, vector<int> (MAXK));

/*float rec(int id, int f, int rem, int cnt){

}*/

int main(){
    while (true){
        cin >> n >> x >> t >> k;
        if (n + x + t + k == 0) break;
        for (auto& a : memo) for (auto& b : a) for (auto& c : b)
            c = -1;
        
        for (int i = 0; i < k; i++){
            cin >> p[i];
            for (int j = 0; j < n; j++)
                cin >> f[j][i];
        }



    }
}
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1001, MAX_P = 13;
int n, m, p;

vector<vector<float>> roads (MAX_N, vector<float>(MAX_N));
vector<int> amazonPrice(MAX_P);

int main(){
    int t;
    cin >> t;
    while (t--){
        cin >> n >> m;
        for (int i = 0; i < m; i++){
            int a, b;
            cin >> a >> b;
            cin >> roads[a][b];
            roads[a][b] = roads[b][a];
        }
        cin >> p;
        for (int i = 0; i < MAX_P; i++)
            amazonPrice[i] = -1;
        for (int i = 0; i < p; i++){
            int a;
            cin >> a;
            cin >> amazonPrice[a];
        }


            



    }
}
#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;

    while (t--){
        int n;
        cin >> n;
        vector<vector<int>> v(5);
        for (int i = 0; i < 5; i++){
            v[i].assign(5, 0);
        }
        for (int i = 0; i < n; i++){
            int a, b;
            cin >> a >> b;
            cin >> v[a][b];
        }   
        
        vector<int> res {0, 0, 0, 0, 0};
        int min = INT32_MAX;
        for (int a = 0; a < 25; a++)
            for (int b = a + 1; b < 25; b++)
                for (int c = b + 1; c < 25; c++)
                    for (int d = c + 1; d < 25; d++)
                        for (int e = d + 1; e < 25; e++){
                            int sum = 0;
                            vector<int> tmp = {a, b, c, d, e};
                            for (int p = 0; p < 25; p++){
                                if (!v[p / 5][p % 5]) continue;
                                int cur = INT32_MAX;
                                for (int i = 0; i < 5; i++){
                                    int dist = v[p/5][p%5] * (abs(tmp[i]/5 - p/5) + abs(tmp[i]%5 - p%5));
                                    if (dist < cur) cur = dist;
                                }
                                sum += cur;
                            }
                            if (sum < min) {
                                min = sum;
                                res = tmp;
                            }
                        } 
        printf("%d %d %d %d %d\n", res[0], res[1], res[2], res[3], res[4]);
    }
        

}


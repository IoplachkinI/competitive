#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    while(!cin.eof()){
        vector<vector<int>> v (n, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> v[i][j];
        
        int cnt = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> res;
        for (int a = 0; a < n; a++)
            for (int b = a + 1; b < n; b++)
                if (v[a][b]) 
                    for (int c = b + 1; c < n; c++)
                        if (v[b][c] && v[c][a]) {
                            cnt++;
                            res.push({a + 1, b + 1, c + 1});
                        }

        for (int a = n - 1; a > -1; a--)
            for (int b = a - 1; b > -1; b--)
                if (v[a][b]) 
                    for (int c = b - 1; c > -1; c--)
                        if (v[b][c] && v[c][a]) {
                            cnt++;
                            res.push({a + 1, b + 1, c + 1});
                        }
            
        while(!res.empty()){
            vector<int> tmp = res.top();
            printf("%d %d %d\n", tmp[0], tmp[1], tmp[2]);
            res.pop();
        }
        printf("total:%d\n\n", cnt);
        cin >> n;
    }
}
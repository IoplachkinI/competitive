#include <bits/stdc++.h>


using namespace std;


int match(vector<string> big, vector<string> small){
    int cnt = 0;

    for (int i = 0; i <= big.size() - small.size(); i++){
        for (int j = 0; j <= big.size() - small.size(); j++){
            bool match = true;
            for (int k = 0; k < small.size() && match; k++){
                match = (big[i + k].substr(j, small.size()).compare(small[k]) == 0);
            }
            cnt += match;
        }
    }

    return cnt;
}


int main(){
    int N, n;
    cin >> N >> n;

    while (n){
        vector <string> big (N);
        vector <string> small (n);

        for (int i = 0; i < N; i++){
            cin >> big[i];
        }  
        for (int i = 0; i < n; i++){
            cin >> small[i];
        } 

        vector<string> _small = small;

        cout << match(big, small);
        for (int a = 0; a < 3; a++){
            for (int j = 0; j < small.size(); j++){
                for (int i = 0; i < small.size(); i++){
                    _small[j][small.size() - 1 - i] = small[i][j];
                }
            }
            cout << ' ' << match(big, _small);
            small = _small;
        }
        
        cout << '\n';
        cin >> N >> n;
    }


}
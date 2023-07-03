#include <bits/stdc++.h>

using namespace std;

int main(){
    map<char, int> m2 {
        {'P', 0}, {'G', 1}, {'S', 2}, {'A', 3}, {'N', 4}
    };
    map<char, int> m1 {
        {'g', 0}, {'y', 1}, {'o', 2}, {'r', 3}, {'b', 4}
    };
    while (1){
        int city = 0;
        vector<vector<int>> cities;
        vector<vector<int>> v (5, vector<int> (5));
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++) v[i][j] = 0;
        string str;
        while (1){
            cities.push_back(vector<int> (5));
            getline (cin, str);
            if (str[0] == 'e' || str[0] == '#') break;

            int j = -2;
            for (int i = 0; i < 5; i++) {
                j += 4;
                v[m1[str[j - 2]]][m2[str[j]]]++;
                cities[city][m1[str[j - 2]]] = m2[str[j]];
            }
            city++;
        }
        vector<int> scores;
        scores.assign(cities.size() + 1, 0);
        int maxInd = 1;
        for (int i = 0; i < cities.size(); i++){
            for (int j = 0; j < 5; j++){
                scores[i + 1] += v[j][cities[i][j]];
            }
            if (scores[i + 1] > scores[maxInd]) maxInd = i + 1;
        }

        if (str[0] == '#') break;
        cout << maxInd << '\n';
    }
}
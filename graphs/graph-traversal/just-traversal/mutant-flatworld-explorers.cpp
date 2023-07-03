#include <bits/stdc++.h>

using namespace std;


int main(){
    const int MAXX = 51, MAXY = 51;
    int maxx, maxy, dirind;
    char dir;
    pair<int, int> curpos;
    string path;
    vector<vector<int>> scented(MAXX, vector<int> (MAXY));

    vector<pair<int, int>> dirToStep {
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0}
    };

    map<char, int> charToDir {
        {'N', 0},
        {'E', 1},
        {'S', 2},
        {'W', 3}
    };

    map<int, char> dirToChar {
        {0, 'N'},
        {1, 'E'},
        {2, 'S'},
        {3, 'W'}
    };

    cin >> maxx >> maxy;
    for (auto& a : scented) for (auto& b : a) b = 0;
    while (true){
        cin >> curpos.first >> curpos.second;
        if (cin.eof()) break;
        cin >> dir;
        dirind = charToDir[dir];
        cin >> path;
        bool lost = false;
        for (int i = 0; i < path.size() && !lost; i++){
            if (path[i] == 'F') {
                curpos.first += dirToStep[dirind].first;
                curpos.second += dirToStep[dirind].second;
            }
            else if (path[i] == 'R') dirind = (dirind + 1) % 4;
            else dirind = (dirind - 1 < 0) ? 3 : dirind - 1;
            
            if (curpos.first > maxx){
                curpos.first--;
                if (scented[curpos.first][curpos.second]) continue;
                scented[curpos.first][curpos.second] = 1;
                lost = true;
            }
            else if (curpos.first < 0){
                curpos.first++;
                if (scented[curpos.first][curpos.second]) continue;
                scented[curpos.first][curpos.second] = 1;
                lost = true;
            }
            else if (curpos.second > maxy){
                curpos.second--;
                if (scented[curpos.first][curpos.second]) continue;
                scented[curpos.first][curpos.second] = 1;
                lost = true;
            }
            else if (curpos.second < 0){
                curpos.second++;
                if (scented[curpos.first][curpos.second]) continue;
                scented[curpos.first][curpos.second] = 1;
                lost = true;
            }
        }
        printf("%d %d %c", curpos.first, curpos.second, dirToChar[dirind]);
        if (lost) printf(" LOST");
        printf("\n");

    }
}
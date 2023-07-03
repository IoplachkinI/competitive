#include <bits/stdc++.h>

using namespace std;

vector<string> v;
vector<int> dr {1, 0, -1, 0};
vector<int> dc {0, 1, 0, -1};

bool addedfirststring, addedlaststring;

void printv(){
    for (const auto& str : v) cout << str << '\n';
}

void floodfill(int r, int c) {
    if (r >= v.size() || r < 0 || c >= v[r].size() || c < 0 || v[r][c] != ' ') return;
    v[r][c] = '#';
    for (int i = 0; i < 4; i++)
        floodfill(r+dr[i], c+dc[i]);
}

void removeExcess(){
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++){
            if (v[i][j] != '#') continue;
            bool nextToChar = false;
            for (int k = 0; k < 4 && !nextToChar; k++) {
                int r = i+dr[k];
                int c = j+dc[k];
                if (r >= v.size() || r < 0 || c >= v[r].size() || c < 0) continue;
                if (v[r][c] != ' ' && v[r][c] != '#') nextToChar = true;
            }
            if (!nextToChar) v[i][j] = ' ';
        }
        int lastpos = v[i].find_last_not_of(' ');
        if (lastpos == string::npos) v[i].resize(0);
        else v[i].resize(lastpos+1);
    }
    if (v[0].find_first_not_of(' ') == string::npos && addedfirststring) v.erase(v.begin());
    if (v[v.size()-1].find_first_not_of(' ') == string::npos && addedlaststring) v.erase(v.end()-1);
}

int main(){
    int t;
    cin >> t;
    cin.ignore(100, '\n');
    while (t--){
        addedfirststring = addedlaststring = false;
        string line;
        int maxlen = 0;
        v.clear();
        while (true){
            string in;
            getline(cin, in);
            if (in[0] == '_') {
                line = in;
                break;
            }
            in += ' ';
            if (in.size() > maxlen) maxlen = in.size();
            v.push_back(in);
        }

        if (v[0].find_first_not_of(' ') != string::npos) {
            v.insert(v.begin(), "");
            addedfirststring = true;
        }
        if (v[v.size()-1].find_first_not_of(' ') != string::npos) {
            v.push_back("");
            addedlaststring = true;
        }

        for (int i = 0; i < v.size(); i++)
            v[i] += string(maxlen-v[i].size(), ' ');

        for (int i = 0; i < v.size(); i++) for (int j = 0; j < v[i].size(); j++)
            if (v[i][j] == '*'){
                v[i][j] = ' ';
                floodfill(i, j);
            }
        removeExcess();
        printv();
        cout << line << '\n';
    }

}
#include <bits/stdc++.h>


using namespace std;


int main(){
    //ifstream in;
    //in.open("in.txt");
    int t;
    cin >> t;
    cin.ignore(100, '\n');
    cin.ignore(100, '\n');
    //ofstream o;
    //o.open("out.txt");

    while (t--){
        vector<vector<bool>> solved (101, vector<bool> (10));
        for (int i = 0; i < solved.size(); i++){
            for (int j = 0; j < solved[i].size(); j++){
                solved[i][j] = false;
            }
        }
        vector<vector<int>> penalties(101, vector<int> (10));
        for (int i = 0; i < penalties.size(); i++){
            for (int j = 0; j < penalties[i].size(); j++){
                penalties[i][j] = 0;
            }
        }

        vector<vector<int>> res (101, vector<int> (3));
        for (int i = 0; i < res.size(); i++){
            res[i][0] = i;
            res[i][1] = -1;
            res[i][2] = 0;
        }

        while (true){
            string str;
            getline(cin, str);
            if (str.size() == 0) break;

            vector<int> info (3);
            string code;
            for (int i = 0; i < 3; i++){
                info[i] = stoi(str.substr(0, str.find(' ')));
                str.erase(str.begin(), str.begin() + str.find(' ') + 1);
            }
            code = str;
            if(res[info[0]][1] == -1) res[info[0]][1] = 0;

            if (code.compare("C") == 0 && solved[info[0]][info[1]] == false){
                solved[info[0]][info[1]] = true;
                penalties[info[0]][info[1]] += info[2];
                res[info[0]][1]++;
            }
            else if (code.compare("I") == 0 && solved[info[0]][info[1]] == false){
                penalties[info[0]][info[1]] += 20;
            }
        }

        for (int i = 0; i < res.size(); i++){
            for (int j = 1; j < 10; j++){
                if (!solved[i][j]) continue;
                res[i][2] += penalties[i][j];
            }
        }

        sort(res.begin(), res.end(), [](vector<int> b, vector<int> a){
            if (a[1] != b[1]) return b[1] > a[1];
            else if (a[2] != b[2]) return b[2] < a[2];
            else return b[0] < a[0];
        });

        for (const auto& el : res){
            if (el[1] == -1) continue;
            cout << el[0] << ' ' << el[1] << ' ' << el[2] << '\n';
        }
        if (t != 0) cout << '\n';

    }
    //o.close();
}
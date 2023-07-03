#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;

#define o cout

int main(){
    //ofstream o;
    //o.open("out.txt");
    string str;
    getline(cin, str);
    vector <ii> v;
    while (str.compare("#")){
        int pos = str.find(' ');
        int id = stoi(str.substr(pos + 1, str.find(' ', pos + 1) - pos - 1));
        pos = str.find(' ', pos + 1);
        int per = stoi(str.substr(pos + 1));
        v.push_back({id, per});
        getline (cin, str);
    }
    int k;
    cin >> k;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    for (const auto& el : v){
        for (int i = 1; i <= k; i++){
            pq.push({el.second * i, el.first});
        }
    }

    for (int i = 0; i < k; i++){
        cout << pq.top().second << '\n';
        pq.pop();
    }

    //o.close();
}
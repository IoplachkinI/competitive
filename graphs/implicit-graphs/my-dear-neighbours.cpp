#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

#define o cout

int main(){
    //ofstream o;
    //o.open("out.txt");
    int n;
    cin >> n;
    while (n--){
        int p;
        cin >> p;
        cin.ignore(100, '\n');
        priority_queue<ii, vector<ii>, greater<ii>> pq;
        for (int i = 0; i < p; i++){
            string str;
            getline(cin, str);
            int pos = str.find(' ');
            int cnt = 1;
            while (pos != string::npos) {
                cnt++;
                pos = str.find(' ', pos + 1);
            }
            pq.push({cnt, i + 1});
        }
        int min = pq.top().first;
        o << pq.top().second;
        pq.pop();
        while (!pq.empty() && pq.top().first == min) {
            o << ' ' << pq.top().second;
            pq.pop();
        }
        o << '\n';
    }
    //o.close();
}
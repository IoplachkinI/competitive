#include <bits/stdc++.h>


using namespace std;

#define o cout

int main(){
    //ofstream o;
    //o.open("out.txt");
    int n;
    cin >> n;
    while (n){
        bool blockEnd = false;
        while (!blockEnd){
            bool possible = true;
            stack <int> station;
            stack <int> entrance;
            for (int i = 0; i < n; i++){
                entrance.push(n - i);
            }

            for (int i = 0; i < n && !blockEnd; i++){
                int num;
                cin >> num;                
                if (num == 0) {
                    blockEnd = true;
                    break;
                }
                while (possible){
                    if (station.empty()) {
                        if (entrance.empty()) break;
                        station.push(entrance.top());
                        entrance.pop();
                    }
                    if (station.top() == num) {
                        station.pop();
                        break;
                    }
                    else if (entrance.empty() || entrance.top() > num) possible = false;
                    else {
                        station.push(entrance.top());
                        entrance.pop();
                    }
                }
            }
            if (blockEnd) break;
            if (possible) o << "Yes\n";
            else o << "No\n";
        }
        cin >> n;
        o << '\n';
    }
    //o.close();
}
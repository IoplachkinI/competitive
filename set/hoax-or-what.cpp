#include <bits/stdc++.h>


using namespace std;

#define o cout

int main(){
    //ofstream o;
    //o.open("out.txt");
    int n;
    cin >> n;
    while (n){
        long long am = 0;
        multiset<int> bills;
        for (int i = 0; i < n; i++){
            int k;
            cin >> k;
            for (int j = 0; j < k; j++){
                int b; cin >> b;
                bills.insert(b);
            }
            am += *(--bills.end()) - *bills.begin();
            bills.erase(--bills.end());
            bills.erase(bills.begin());
        }
        o << am << '\n';
        cin >> n;
    }
    //o.close();
}
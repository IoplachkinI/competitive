#include <bits/stdc++.h>

using namespace std;

int main(){
    while (true){
        int money;
        cin >> money;
        printf("%d.%02d$", money / 100, money % 100);
    }
}
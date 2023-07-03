#include <bits/stdc++.h>


using namespace std;


int main(){
    for (int x = 4; x <= 490; x+=4){
        double y = (sqrt(490) - sqrt(x)) * (sqrt(490) - sqrt(x));
        if (fabs(y - roundf(y)) < 0.0001) cout << x << endl;
        }

}

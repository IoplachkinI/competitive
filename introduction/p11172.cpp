#include <iostream>


using namespace std;
typedef long long ll;


int main(){
    ll t;
    cin >> t;

    while (t--){
        ll num1, num2;
        cin >> num1 >> num2;

        if (num1 > num2) cout << ">\n";
        else if (num1 < num2) cout << "<\n";
        else cout << "=\n";
    }

}
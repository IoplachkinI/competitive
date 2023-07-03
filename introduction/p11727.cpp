#include <iostream>
#include <algorithm>


using namespace std;


int main(){
    int t;
    cin >> t;

    for (int i = 0; i < t; i++){
        int a[3];
        cin >> a[0] >> a[1] >> a[2];

        sort(a, a + 3);
        cout << "Case " << i + 1 << ": " << a[1] << '\n';
    }

    return 0;
}
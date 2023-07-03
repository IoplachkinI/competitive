#include <iostream>


using namespace std;


int main(){
    int t;
    cin >> t;
    while (t != 0){
        int n, m;
        cin >> n >> m;

        while (t--){
            int x, y;
            cin >> x >> y;
            
            if (x == n || y == m) cout << "divisa\n";
            else if (x > n){
                if (y > m) cout << "NE\n";
                else if (y < m) cout << "SE\n";
            }
            else if (x < n){
                if (y > m) cout << "NO\n";
                else if (y < m) cout << "SO\n";
            }

        }

        cin >> t;
    }

}
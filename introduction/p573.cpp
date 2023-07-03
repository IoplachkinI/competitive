#include <iostream>
#include <cmath>

#define EPSILON 0.0000001

using namespace std;

int main(){
    double h, u, d, f;
    while (true){
        cin >> h >> u >> d >> f;
        if (h < EPSILON) break;

        double v = u;
        double s = 0;
        int day = 0;

        do {
            day++;
            s += v;
            if (s - h > EPSILON) {
                cout << "success on day " << day << '\n';
                break;
            }
            s -= d;
            if (s < -EPSILON) {
                cout << "failure on day " << day << '\n';
                break;
            }
            v = (v - u * f / 100.0) * (v - u * f / 100.0 > EPSILON);
        } while (true);

    }
}
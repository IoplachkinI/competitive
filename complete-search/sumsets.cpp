#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int bin (vector<int>& v, int n){
    int start = 0, end = v.size();
    while (start < end){
        int mid = (end + start) / 2;
        if (n > v[mid]) start = mid + 1;
        else if (n < v[mid]) end = mid;
        else return mid;
    }
    return -1;

}

int main(){
    int n;
    cin >> n;
    while (n){
        vector<int> v(n);
        for (int i = 0; i < n; i++){
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        long long max = LONG_LONG_MIN;
        for (int a = 0; a < n; a++){
            for (int b = a + 1; b < n; b++){
                for (int c = b + 1; c < n; c++){
                    int sum = v[a] + v[b] + v[c];
                    int ind = bin(v, sum);
                    if (ind > -1 && ind != a && ind != b && ind != c &&
                    sum > max) max = sum;
                }
            }
        }
        if (max == LONG_LONG_MIN) cout << "no solution\n";
        else cout << max << "\n";
        cin >> n;
    }
}
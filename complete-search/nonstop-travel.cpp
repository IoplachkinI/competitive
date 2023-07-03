#include <bits/stdc++.h>

using namespace std;

int main(){
    int k, cnt = 0;
    cin >> k;
    while (k != -1){
        cnt++;
        vector<vector<double>> v (k, vector<double> (4));
        vector<int> speeds(70);
        speeds.assign(70, 0);
        for (int i = 0; i < k; i++){
            cin >> v[i][0] >> v[i][1] >> v[i][2] >> v[i][3];
        }

        for (int s = 30; s <= 60; s++){
            bool good = true;
            for (int i = 0; i < k && good; i++){
                double cycle = v[i][1] + v[i][2] + v[i][3];
                double time = v[i][0] / (s / 3600.0);
                double n = floor(time / cycle);
                // n = round(length / (speed in miles/second) / (traffic light cycle in seconds))
                if (n * cycle + v[i][1] + v[i][2] < time) good = false;
            }
            if (good) {
                speeds[s] = 1;
            }
        }

        printf("Case %d:", cnt);
        int start = INT32_MIN, end = INT32_MIN;
        bool first = true;
        for (int i = 30; i <= 61; i++){
            if (speeds[i] && i > end + 1) {
                start = i;
                end = i;
            }
            else if (speeds[i]) end = i;

            if (!speeds[i] && i == end + 1) {
                if (!first) printf(",");
                else first = false;

                if (start == end) printf(" %d", start);
                else printf(" %d-%d", start, end);


            }
        }
        if (first) printf(" No acceptable speeds.");
        printf("\n");
        cin >> k;
    }
}
#include <bits/stdc++.h>


using namespace std;


int main(){
    int r, p;
    int count = 0;
    scanf("%d %d ", &r, &p);

    while (r != 0){
        count++;

        for (int i = 0; i < r; i++) scanf ("%*[^\n] ");

        vector <tuple<string, double, int, int>> v;

        for (int i = 0; i < p; i++){
            char c[85];
            double price;
            int req;
            scanf ("%*[^0-9] %s %lf %d ", c, &price, &req);

            v.push_back({c, price, req, i});
            
            for (int j = 0; j < req; j++){
                scanf ("%*[^\n] ");
            }
        }

        std::sort (v.rbegin(), v.rend(), [](const tuple<string, double, int, int>& el1, const tuple<string, double, int, int>& el2){
            if (get<2>(el1) != get<2> (el2)) return get<2>(el1) < get<2>(el2);
            if (get<1>(el1) != get<1>(el2)) return get<1>(el1) < get<1>(el2);
            return get<3>(el1) < get<3>(el2);
        });

        cout << "REP #" << count << '\n' << get<0>(v[0]);
        scanf("%d %d ", &r, &p);
    }

    return 0;

}
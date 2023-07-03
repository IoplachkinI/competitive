#include <bits/stdc++.h>
#define PI 3.14159265358979323846


using namespace std;


void p2(){
    int n;
    cin >> n;

    printf ("%.*lf\n", n, PI);
}


void p3(){
    int n;
    cin >> n;
    set <int> s;
    

    for (int i = 0; i < n; i++){
        s.insert(rand() % n);
    }

    for (const auto& el : s) {
        cout << el << '\n';
    }

}


void p4(){
    vector<tuple<int, int, int>> v;

    int n;
    scanf("%d", &n);

    while (n--){
        int a, b, c;
        scanf("%d,%d,%d", &a, &b, &c);
        v.push_back({a, b, c});
    }
    printf ("%d\n", v.size());
    //for(const auto& el : v) printf("%d.%d.%d\n", get<0>(el), get<1>(el), get<2>(el)); 

    sort(v.begin(), v.end(), [](const tuple<int, int, int>& el1, const tuple<int, int, int>& el2){
        return get<1>(el1) < get<1>(el2);
    });
    for(const auto& el : v) printf("%d.%d.%d\n", get<0>(el), get<1>(el), get<2>(el)); 

    sort(v.begin(), v.end(), [](const tuple<int, int, int>& el1, const tuple<int, int, int>& el2){
        return get<0>(el1) < get<0>(el2);
    });
    for(const auto& el : v) printf("%d.%d.%d\n", get<0>(el), get<1>(el), get<2>(el)); 

    sort(v.begin(), v.end(), [](const tuple<int, int, int>& el1, const tuple<int, int, int>& el2){
        if (get<2>(el1) != get<2> (el2)) return get<2>(el1) < get<2> (el2);
        if (get<1>(el1) != get<1> (el2)) return get<1>(el1) < get<1> (el2);
        return get<0>(el1) < get<0>(el2);
    });
    for(const auto& el : v) printf("%d.%d.%d\n", get<0>(el), get<1>(el), get<2>(el)); 

}


int main(){
    srand(time(0));
    p4();
}
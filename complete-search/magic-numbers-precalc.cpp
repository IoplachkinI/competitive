#include <bits/stdc++.h>

using namespace std;

int main(){
    ofstream o;
    o.open("magic.txt");

    for (char a1 = '0'; a1 <= '9'; a1++)
    for (char a2 = '0'; a2 <= '9'; a2++)
    for (char a3 = '0'; a3 <= '9'; a3++)
    for (char a4 = '0'; a4 <= '9'; a4++)
    for (char a5 = '0'; a5 <= '9'; a5++)
    for (char a6 = '0'; a6 <= '9'; a6++)
    for (char a7 = '0'; a7 <= '9'; a7++)
    for (char a8 = '0'; a8 <= '9'; a8++)
    for (char a9 = '0'; a9 <= '9'; a9++)
    for (char a10 = '0'; a10 <= '9'; a10++)
    {
        string str = "";
        str = str + a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9 + a10;
        set<char> s;
        bool good = true;
        for (const auto& el : str){
            if (s.count(el)){
                good = false;
                break;
            }
            s.insert(el);
        }
        if (good) o << str << ",\n";
    }


    o.close();
}
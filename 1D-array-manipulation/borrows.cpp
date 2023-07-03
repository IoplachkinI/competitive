#include <bits/stdc++.h>


using namespace std;


int main(){
    string name;
    vector<pair<string, string>> origin;
    getline(cin, name);

    while (name.compare("END")){
        string book, author;
        
        book += '"';
        for (int i = 1; i < name.size(); i++){
            book += name[i];
            if (name[i] == '"') break;
        }

        author.append(name.begin() + name.find(" by ") + 4, name.end());

        origin.push_back({author, book});

        getline(cin, name);
    }

    sort(origin.begin(), origin.end());

    vector<pair<string, string>> current = origin;
    vector<string> shelve;

    string command;
    getline(cin, command);

    while (command.compare("END")){
        if (command.find("BORROW") != string::npos) {
            for (int i = 0; i < current.size(); i++){
                if (current[i].second.compare(command.substr(7)) == 0) {
                    current.erase(current.begin() + i);
                    break;
                }
            }
        }

        else if (command.find("RETURN") != string::npos) {
            for (int i = 0; i < origin.size(); i++){
                if (origin[i].second.compare(command.substr(7)) == 0) {
                    for (int j = 0; j < current.size(); j++){
                        if (current[j].first.compare(origin[i].first) >= 0 &&
                            current[j].second.compare(origin[i].second) >= 0){
                                current.insert(current.begin() + j, origin[i]);
                                if (j == 0) shelve.push_back ("Put " + origin[i].second + " first\n");
                                else shelve.push_back ("Put " + origin[i].second + 
                                " after " + current[j-1].second + '\n');
                            }
                    }
                    break;
                }
            }
        }

        else if (command.find("SHELVE") != string::npos){
            for (const auto& el : shelve) {
                cout << el;
            }
            shelve.clear();
        }

        getline(cin, command);
    }
}
/*
ID: xerxes.1
PROG: namenum
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

const string NONE("NONE");
const string KEYPAD("ABCDEFGHIJKLMNOPRSTUVWXY");

int str2key(string s) {
    int i = 0;
    for (char& c : s) {
        i *= 10;
        size_t found = KEYPAD.find(c);
        if (found != string::npos) {
            i += found / 3 + 2;
        } else {
            return 0;
        }
    }
    return i;
}

int main() {
    ifstream fin ("namenum.in");
    ifstream fdict ("dict.txt");
    ofstream fout ("namenum.out");

    map<int, string> dict;
    string t;
    while (!fdict.eof()) {
        fdict >> t;
        int key = str2key(t);
        if (key != 0)
            dict[key] = t;
    }

    int key;
    fin >> key;

    auto it = dict.find(key);
    if (it == dict.end()) {
        fout << NONE << endl;
    } else {
        fout << it->second << endl;
    }

    return 0;
}

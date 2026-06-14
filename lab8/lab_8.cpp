#include <iostream>
#include <string>
#include <map>
#include <fstream>

using namespace std;

ifstream fin("text.txt");

int main() {

    string sentence;
    string currentWord = "";

    getline(fin,sentence);
   
    map<string, int> m;

    for (int i = 0; sentence[i] != '\0'; i++)
        if (sentence[i] > 64 && sentence[i] < 91)
            sentence[i] = sentence[i] + ('a' - 'A');

    for (int i = 0; i < sentence.length(); ++i) {

        if (sentence[i] == ' '|| sentence[i] == '.'|| sentence[i] == ','|| sentence[i] == '!'|| sentence[i] == '?') {
            if (currentWord != "") {
                m[currentWord] = m[currentWord] + 1;
                currentWord = "";
            }
        }
        else {
            currentWord += sentence[i];
        }
    }

    if (currentWord != "") {
        m[currentWord] = m[currentWord] + 1;
    }

    map<int, map<string, bool>> orderedMap;

    for (const auto& pair : m) {
        orderedMap[pair.second][pair.first] = true;
    }

    char x = '"';

    for (auto outer = orderedMap.rbegin(); outer != orderedMap.rend(); ++outer) {

        for (auto inner = outer->second.begin(); inner != outer->second.end(); ++inner) {

            cout <<x << inner->first <<x<< ": " << outer->first << endl;
        }
    }

    return 0;
}

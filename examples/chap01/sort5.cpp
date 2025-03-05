#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> sort(vector<string> words) {
    sort(words.begin(), words.end());
    return words;
}

int main(int argc, char *argv[]) {
    // Lege einen leeren Vektor von Strings an
    vector<string> words;
    
    // kopiere die Kommandozeilenargumente
    for (int i{1}; i < argc; ++i) {
        words.push_back(argv[i]);
    }

    words = sort(words);

    // und gib die Worte wieder aus
    for (int i{0}; i < words.size(); ++i) {
        cout << words[i] << endl;
    }
}
